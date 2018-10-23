#include <iostream>
#include <vector>

using namespace std;


int NumOf1(int num)              //统计其中的1的个数

{  

    int count = 0;  

    while (num)  

    {  

        num = num & (num - 1);  

        count++;  

    }  

    return count;  

}  

  

void CalSum(vector<float> &nums, float resleft, float resright, int m)    

{  

    int len = nums.size();  

    int bit = 1 << len;  

    for (int i = 1; i < bit; i++)                //从1循环到2^N    

    {    

        float sum = 0;    

        vector<float> tmp;  

        if (NumOf1(i) == m)  

        {  

            for (int j = 0; j < len; j++)    

            {    

                if ((i & 1 << j) != 0)        //用i与2^j进行位与运算，若结果不为0,则表示第j位不为0,从数组中取出第j个数    

                {    

                    sum += nums[j];    

                    tmp.push_back(nums[j]);    

                }    

            }    

            if (sum >= resleft && sum <= resright)  

            {  

                for (vector<float>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)  

                {  

                    cout << *iter << " ";  

                }  

                cout << endl;  

            }  

        }  

    }    

}   


int main()
{
	float a[24]={140.24,188.52,377.70,331.71,215.81,209.06,182.61,135.26,162.40,1943.31,379.89,390.04,454.26,317.86,575.48,589.23,454.50,390.05,357.18,296.79,482.61,117.90,218.45,101.38};
	vector<float> vecarr(a, a+24);
	float left = 1585;
	float right = 1590;
	
	
	CalSum(vecarr, left, right, 7);
	
	
	
}






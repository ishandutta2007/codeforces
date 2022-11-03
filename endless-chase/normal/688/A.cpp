#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
	 char a[105];
    int n,d;
    cin>>n>>d;
        int sum=0,lvpinjiewangyihanzhaoyouranyeyuyang=0;
        for(int i=0;i<d;i++)
        {
            int flag=0;
            scanf("%s",a);
            for(int j=0;j<n;j++)
            {
                if(a[j]=='0')
                {
                    flag=1;
                }
            }
            if(flag)
            {
                sum++;
                lvpinjiewangyihanzhaoyouranyeyuyang=max(lvpinjiewangyihanzhaoyouranyeyuyang,sum);
            }
            else
            {
                lvpinjiewangyihanzhaoyouranyeyuyang=max(lvpinjiewangyihanzhaoyouranyeyuyang,sum);
                sum=0;
            }
        }
        cout<<lvpinjiewangyihanzhaoyouranyeyuyang;
    
	return 0;
}
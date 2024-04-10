#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,sum[300001][2];
string s1,s2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s1>>s2;
        s1=" "+s1;
        s2=" "+s2;
        for(register int i=1;i<=n;++i)
        {
            sum[i][0]=sum[i-1][0]+(s1[i]=='1');
            sum[i][1]=sum[i-1][1]+(s2[i]=='1');
        }
        bool flag=1,tag=0;
        for(register int i=n;i>=1;--i)
        {
            if((s1[i]-'0')^tag==s2[i]-'0')
                continue;
            if((i&1)||sum[i][0]!=(i>>1))
            {
                flag=0;
                puts("NO");
                break;
            }
            tag^=1;
        }
        if(flag)
            puts("YES");
    }
    return 0;
}
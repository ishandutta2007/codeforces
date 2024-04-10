#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int t,n,ans,sum,cnt,a[101];
string s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        n=s.length();
        ans=sum=cnt=0;
        for(register int i=0;i<n;++i)
        {
            if(s[i]=='0'&&sum)
            {
                a[++cnt]=sum;
                sum=0;
            }
            if(s[i]=='1')
                ++sum;
        }
        if(sum)
            a[++cnt]=sum;
        sort(a+1,a+cnt+1);
        for(register int i=cnt;i>=1;i-=2)
            ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}
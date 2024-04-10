#include<iostream>
#include<cstdio>
using namespace std;
long long t,n,sum,ans;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        bool flag=1;
        ans=sum=0;
        for(register int i=1;i<=n;++i)
        {
            long long x;
            scanf("%lld",&x);
            ans+=i-1;
            sum+=x;
            if(sum<ans)
                flag=0;
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
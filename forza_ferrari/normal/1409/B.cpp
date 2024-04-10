#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,a,b,x,y,n,ans;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&n);
        ans=0;
        if(a-x+b-y<=n)
        {
            printf("%lld\n",x*y);
            continue;
        }
        int a1=max(x,a-n),b1=b-(n-(a-a1));
        ans=a1*b1;
        a^=b^=a^=b;
        x^=y^=x^=y;
        a1=max(x,a-n);
        b1=b-(n-(a-a1));
        ans=min(ans,a1*b1);
        printf("%lld\n",ans);
    }
    return 0;
}
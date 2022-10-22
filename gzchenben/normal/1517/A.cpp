#include<cstdio>
#include<algorithm>
using namespace std;
int t;
long long n,p[16];
int main()
{
    scanf("%d",&t);
    p[0]=1;
    for(int i=1;i<=15;i++)
    {
        p[i]=p[i-1]*10;
    }
    while(t--)
    {
        scanf("%lld",&n);
        int now=15,ans=0;
        while(now>=0)
        {
            ans+=n/(p[now]*2050);
            n=n%(p[now]*2050);
            now--;
        }
        if(n!=0) printf("-1\n");
        else printf("%d\n",ans);
    }
}
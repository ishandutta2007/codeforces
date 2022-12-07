#include<cstdio>
#include<algorithm>
using namespace std;
int n,t;
long long k,x[200005];
long long gcd(long long x,long long y)
{
    if(x>y) swap(x,y);
    if(x==0) return y;
    else return gcd(y%x,x); 
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        sort(x+1,x+n+1);
        long long tmp=x[2]-x[1];
        for(int i=3;i<=n;i++)
        {
            tmp=gcd(tmp,x[i]-x[i-1]);
        }
        if((k-x[1])%tmp==0) printf("YES\n");
        else printf("NO\n");
    }
}
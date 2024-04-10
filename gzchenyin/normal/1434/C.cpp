#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a,b,c,d;
long long calc(long long x)
{
//    printf("----------------\ncalc:a=%lld,b=%lld,c=%lld,d=%lld,x=%lld\n",a,b,c,d,x);
    long long ans=x*(a-b*c);
//    printf("ans=%lld\n",ans);
    long long First=c;
//    printf("First=%lld\n",First);
    long long Diff=d;
//    printf("Diff=%lld\n",Diff);
    long long Number=min((c/d)+1,x);
//    printf("Number=%lld\n",Number);
    long long Last=First-(Number-1)*Diff;
//    printf("Last=%lld\n",Last);
//    printf("returned:%lld\n",ans+(First+Last)*Number*b/2ll);
    return ans+(First+Last)*Number*b/2ll;
}
bool check(long long x)
{
    return (calc(x+1)-calc(x))>0;
}
int main()
{
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(b*c<a) 
        {
            printf("-1\n");
            continue;
        }
        int L=1,R=1000001;
        while(L<R)
        {
            int mid=(L+R)/2;
            if(check(mid)) L=mid+1;//midmid+1>0
            else R=mid;
        }
        printf("%lld\n",calc(L));
    }
}
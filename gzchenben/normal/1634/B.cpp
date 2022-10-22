#include<cstdio>
using namespace std;
int t,n;
long long x,y;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld%lld",&n,&x,&y);
        long long cnt=x;
        for(int i=1;i<=n;i++)
        {
            long long tmp;
            scanf("%lld",&tmp);
            cnt=cnt^tmp;
        }
        printf((cnt-y)%2==0 ? "Alice\n" : "Bob\n");
    }
}
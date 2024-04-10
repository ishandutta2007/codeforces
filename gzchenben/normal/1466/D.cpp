#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    int w;
    int deg;
}a[100005];
bool cmp(node x,node y)
{
    return x.w>y.w;
}
int n,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].w);
            sum+=a[i].w;
        }
        printf("%lld ",sum);
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            a[u].deg++;
            a[v].deg++;
        }
        sort(a+1,a+n+1,cmp);
        int now=1;
        for(int i=1;i<=n-2;i++)
        {
            while(a[now].deg==1) now++;
            sum+=a[now].w;
            a[now].deg--;
            printf("%lld ",sum);
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            a[i].deg=a[i].w=0;
        }
    }
}
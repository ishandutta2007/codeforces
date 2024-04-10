#include<cstdio>
int ans,n;
int c[1000010];
int main()
{
    scanf("%d",&n);ans=0;
    for (int i=1;i<=n;i++) c[i]=c[i-1]^i;
    for (int i=1;i<=n;i++)
    {
        ans^=((n/i)&1)*c[i-1];
        ans^=c[n%i];
    }
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans^=x;
    }
    printf("%d\n",ans);
    return 0;
}
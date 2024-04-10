#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[300005],v[300005],pre[300005],nxt[300005],st[300005],top;
long long dp[300005];
struct node 
{
    int l,r;
}p[600005];
bool cmp(node x,node y)
{
    return x.r<y.r;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        while(a[st[top]]>a[i]) top--;
        pre[i]=st[top];
        st[++top]=i;
        if(pre[i]!=0) p[++m]=(node){pre[i]+1,i};
    }
    top=0;
    st[top]=n+1;
    for(int i=n;i>=1;i--)
    {
        while(a[st[top]]>a[i]) top--;
        nxt[i]=st[top];
        st[++top]=i;
        if(nxt[i]!=n+1) p[++m]=(node){i,nxt[i]-1};
    }
    // for(int i=1;i<=m;i++)
    // {
    //     printf("node(%d %d %lld)\n",p[i].l,p[i].r,p[i].val);
    // }
    sort(p+1,p+m+1,cmp);
    int now=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+v[i];
        while(p[now].r==i) 
        {
            dp[i]=max(dp[i],dp[p[now].l-1]);
            now++;
        }
    }
    printf("%lld\n",dp[n]);
}
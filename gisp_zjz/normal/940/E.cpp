#include<bits/stdc++.h>
#define maxn 203400

using namespace std;
typedef long long ll;
int n,c,r;
ll ans,sum,a[maxn],dp[maxn],b[maxn][20],s,h[maxn];

ll rmq(int x,int y)
{
    r=0; while (x+(1<<r)-1<y-(1<<r)+1) r++;
    return min(b[x][r],b[y-(1<<r)+1][r]);
}

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,ll y)
{
    while (x<maxn) dp[x]=max(dp[x],y),x+=lowbit(x);
}

ll qry(ll x)
{
    ll tmp=0;
    while (x) tmp=max(tmp,dp[x]),x-=lowbit(x);
    return tmp;
}

int main()
{
    scanf("%d%d",&n,&c);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++) ans+=a[i];
    for (int i=1;i<=n;i++) b[i][0]=a[i];
    for (int j=1;j<20;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            b[i][j]=min(b[i][j-1],b[i+(1<<(j-1))][j-1]);
    for (int i=c;i<=n;i++)
    {
        h[i]=qry(i-1);
        h[i]=max(h[i],h[i-c]+rmq(i-c+1,i));
        update(i,h[i]);
    }
    ans-=qry(n);
    printf("%lld\n",ans);
    return 0;
}
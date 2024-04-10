#include<bits/stdc++.h>
#define maxn 1020
#define mod 1000000007

using namespace std;
typedef long long ll;
ll p[maxn],a[maxn],b[maxn],dp[maxn][maxn],n,m,c[maxn],cnt,ans,t,r;
char s[maxn][maxn];
ll q[maxn];

ll pow_(ll x,ll y)
{
    if (y==0) return 1;
    ll tmp=pow_(x,y/2);
    tmp=tmp*tmp%mod;
    if (y&1) tmp=tmp*x%mod;
    return tmp;
}

ll query(ll x,ll y)
{
    if (dp[x][y]!=-1) return dp[x][y];
    if (x==0) return 1;
    if (x<y) return 0;
    ll tmp=0;
    for (int i=0;y*i<=x;i++)
    {
        ll j=query(x-y*i,y+1);
        j=j*pow_(q[y],i)%mod;
        tmp=(tmp+j*q[i])%mod;
    }
    dp[x][y]=tmp;
    return tmp;
}

ll qry(ll x)
{
    memset(dp,-1,sizeof(dp));
    return query(x,1)*p[x]%mod;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) scanf("%s",s[i]);
    p[0]=1;
    for (int i=1;i<maxn;i++) p[i]=p[i-1]*i%mod;
    for (int i=0;i<maxn;i++) q[i]=pow_(p[i],mod-2);
    memset(c,0,sizeof(c));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            c[i]=c[i]+(((ll)(s[j][i]-'0'))<<j);
    sort(c,c+n); c[n]=(ll(1))<<n;
    ans=1; cnt=1;
    for (int i=0;i<n;i++)
    {
        if (c[i]==c[i+1]) cnt++;
        else ans=ans*qry(cnt)%mod,cnt=1;
    }
    printf("%d\n",ans);
    return 0;
}
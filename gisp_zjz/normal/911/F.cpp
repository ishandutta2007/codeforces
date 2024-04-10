#include<bits/stdc++.h>
#define maxn 250300

using namespace std;
typedef long long ll;

ll a[maxn],pre[maxn],b[maxn],t[maxn],c[maxn],g[maxn];
vector <ll> h[maxn];
vector <ll> dp[maxn];
bool vis[maxn],f[maxn];
ll n,r,q,len,k,m,p;
ll ans,d[maxn];

void dfs(ll x)
{
    queue <ll> qr;
    while (!qr.empty()) qr.pop();
    qr.push(x);
    while (!qr.empty())
    {
        ll u=qr.front();qr.pop();vis[u]=true;b[u]=k;
        for (ll i=0;i<h[u].size();i++)
        {
            ll tmp=h[u][i];
            if (f[tmp]&&!vis[tmp])
            {
                d[tmp]=d[u]+1;
                pre[tmp]=u;
                qr.push(tmp);
            }
        }
    }
}

int main()
{
    scanf("%I64d",&n);
    for (ll i=1;i<n;i++)
    {
        ll u,v;
        scanf("%I64d%I64d",&u,&v);
        //u=i;v=i+1;
        h[u].push_back(v);
        h[v].push_back(u);
    }
    k=0;
    memset(f,true,sizeof(f));
    memset(vis,false,sizeof(vis));
    d[1]=0;dfs(1);r=1;
    for (ll i=1;i<=n;i++) if (d[i]>d[r]) r=i;
    memset(vis,false,sizeof(vis));
    d[r]=0;dfs(r);q=r;
    for (ll i=1;i<=n;i++) if (d[i]>d[q]) q=i;
    len=d[q];m=0;g[q]=m; p=q;
    ans=(len+1)*len/2;
    memset(vis,false,sizeof(vis));
    f[q]=false;
    while (q!=r){
        q=pre[q];
        g[q]=++m;
        c[m]=q;
        f[q]=false;
    }
    for (ll i=1;i<=n;i++) if (!f[i]) k=g[i],d[i]=0,dfs(i);
    for (ll i=1;i<=n;i++) if (f[i]) ans=ans+d[i]+max(b[i],len-b[i]);
    printf("%I64d\n",ans);
    for (ll i=1;i<=n;i++) dp[d[i]].push_back(i);
    for (ll j=n;j>=1;j--)
    {
        for (ll i=0;i<dp[j].size();i++)
        {
            ll u=dp[j][i];
            if (b[u]>len-b[u]) printf("%I64d ",p); else printf("%I64d ",r);
            printf("%I64d %I64d\n",u,u);
        }
    }
    for (ll i=len;i>0;i--) printf("%I64d %I64d %I64d\n",p,c[i],c[i]);
    return 0;
}
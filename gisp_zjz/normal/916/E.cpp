#include<bits/stdc++.h>
#define maxn 102020

using namespace std;
typedef long long ll;

ll a[maxn],pre[maxn][20],n,s[maxn],cnt,b[maxn],r[maxn],dep[maxn],l[maxn],p[maxn],rt;
vector <ll> h[maxn];
ll query;
bool vis[maxn];

void dfs(ll x)
{
    l[x]=++cnt;
    p[cnt]=x;
    r[x]=l[x];
    vis[x]=true;
    for (ll i=0;i<h[x].size();i++)
    {
        ll y=h[x][i];
        if (!vis[y]){
            pre[y][0]=x;
            dep[y]=dep[x]+1;
            dfs(y);
            r[x]=cnt;
        }
    }
}

ll pr(ll x,ll y)
{
    if (y<0) return -1;
    for (ll i=19;i>=0;i--)
    {
        if (y>=(1<<i)){
            x=pre[x][i];
            y-=(1<<i);
        }
    }
    return x;
}

ll lca(ll x,ll y)
{
    if (dep[x]>dep[y]) swap(x,y);
    y=pr(y,dep[y]-dep[x]);
    if (x==y) return x;
    for (ll i=19;i>=0;i--)
    {
        if (pre[x][i]!=pre[y][i]){
            x=pre[x][i];
            y=pre[y][i];
        }
    }
    return pre[x][0];
}

ll lowbit(ll x)
{
    return x&(-x);
}

void add1(ll x,ll y)
{
    while (x<maxn)
    {
        a[x]+=y;
        x+=lowbit(x);
    }
}

void add2(ll x,ll y)
{
    while (x<maxn)
    {
        b[x]+=y;
        x+=lowbit(x);
    }
}

ll gets1(ll x)
{
    ll tmp=0;
    while (x)
    {
        tmp+=a[x];
        x-=lowbit(x);
    }
    return tmp;
}

ll gets2(ll x)
{
    ll tmp=0;
    while (x)
    {
        tmp+=b[x];
        x-=lowbit(x);
    }
    return tmp;
}

ll gets(ll x)
{
    if (x<=0) return 0;
    return gets1(r[x])*r[x]-gets1(l[x]-1)*(l[x]-1)+gets2(r[x])-gets2(l[x]-1);
}

bool fa(ll x,ll y)
{
    return pr(x,dep[x]-dep[y])==y;
}

int main()
{
    scanf("%I64d%I64d",&n,&query);
    for (ll i=1;i<=n;i++) scanf("%I64d",&s[i]);
    for (ll i=1;i<n;i++)
    {
        ll u,v;scanf("%I64d%I64d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    cnt=0; rt=1;
    memset(vis,false,sizeof(vis));
    dep[1]=0; pre[1][0]=1; dfs(1);
    for (ll i=1;i<20;i++)
        for (ll j=1;j<=n;j++)
            pre[j][i]=pre[pre[j][i-1]][i-1];
    for (ll i=1;i<=n;i++)
    {
        add1(l[i],s[i]);
        add1(l[i]+1,-s[i]);
        add2(l[i],s[i]*(1-l[i]));
        add2(l[i]+1,s[i]*l[i]);
    }
    while (query--)
    {
        ll u,v,w,c,tp,uw,vw;
        scanf("%I64d",&tp);
        if (tp==1){
            scanf("%I64d",&u);
            rt=u;
        }
        else if (tp==2)
        {
            scanf("%I64d%I64d%I64d",&u,&v,&c);
            w=lca(u,v)^lca(u,rt)^lca(v,rt);
            /*
            uw=lca(u,rt);
            vw=lca(v,rt);
            if (!fa(w,rt)) w=(dep[uw]>dep[vw])?uw:vw;
            if (n==50) {
                printf("%I64d %I64d %I64d\n",u,v,rt);
                printf("%I64d\n",w);
            }
            */
            if (fa(rt,w)){
                add1(1,c);
                w=pr(rt,dep[rt]-dep[w]-1);
                if (w>0){
                    add1(l[w],-c);
                    add1(r[w]+1,c);
                    add2(l[w],c*(l[w]-1));
                    add2(r[w]+1,c*(-r[w]));
                }
            }
            else {
                add1(l[w],c);
                add1(r[w]+1,-c);
                add2(l[w],c*(1-l[w]));
                add2(r[w]+1,c*r[w]);
            }
        }
        else if (tp==3)
        {
            scanf("%I64d",&u);
            if (fa(rt,u)) printf("%I64d\n",gets(1)-gets(pr(rt,dep[rt]-dep[u]-1)));
            else printf("%I64d\n",gets(u));
        }
    }
    return 0;
}
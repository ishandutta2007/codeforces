#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=3E5+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
vct toy[N],toz[N];
int fa[N],son[N],siz[N],top[N];
int dfn[N],cnt;
int q[N],pos[N],n,ans;
void push(int x,int op)
{
    for(int i=dfn[x];i<=n;i+=i&-i)q[i]+=op;
    cnt+=op;
    pos[top[x]]=~op?x:0;
}
int ask(int x)
{
    int res=0;
    for(;x;x-=x&-x)res+=q[x];
    return res;
}
void dfs1(int x)
{
    dfn[x]=++cnt;
    siz[x]=1;
    son[x]=0;
    for(int t:toz[x])
    {
        if(t==fa[x])continue;
        dfs1(t);
        siz[x]+=siz[t];
        if(siz[t]>siz[son[x]])son[x]=t;
    }
}
void dfs2(int x,int p)
{
    top[x]=p;
    for(int t:toz[x])
    {
        if(t!=fa[x])
        {
            dfs2(t,t==son[x]?p:t);
        }
    }
}
void dfs3(int x,int f)
{
    int a[2],s=0;
    if(ask(dfn[x]-1)==ask(siz[x]))
    {
        for(int i=x,u=top[i];i;u=top[i=fa[u]])
        {
            if(pos[u]&&dfn[pos[u]]<=dfn[i])
            {
                a[s++]=pos[u];
                push(pos[u],-1);
                break;
            }
        }
        a[s++]=-x;
        push(x,1);
        ans=max(ans,cnt);
    }
    for(int t:toy[x])dfs3(t,x);
    for(int i=s;i--;)a[i]>0?push(a[i],1):push(-a[i],-1);
}
void solve()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        toy[i].clear();
        toz[i].clear();
    }
    for(int i=2;i<=n;++i)toy[read()].pb(i);
    for(int i=2;i<=n;++i)toz[fa[i]=read()].pb(i);
    dfs1(1);
    dfs2(1,1);
    for(int i=1;i<=n;++i)siz[i]+=dfn[i]-1;
    ans=cnt=0;
    dfs3(1,0);
    write(ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}
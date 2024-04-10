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
const int N=2E5+10;
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
vct to[N];
pii l[N],r[N];
bitset<N>b;
int root,targ;
int du[N],dep[N];
void dfs1(int y,int x,int f,int d)
{
    if(du[x]>2)
    {
        pii t=mp(d,y);
        if(t>l[x])
        {
            r[x]=l[x];
            l[x]=t;
        }
        else if(t>r[x])
        {
            r[x]=t;
        }
        b[f]=1;
    }
    else
    {
        for(int t:to[x])
        {
            if(t==f)continue;
            dfs1(y,t,x,d+1);
        }
    }
}
void dfs2(int x,int f)
{
    if(dep[x]>dep[targ]||dep[x]==dep[targ]&&l[x].fi>l[targ].fi)targ=x;
    for(int t:to[x])
    {
        if(t==f||b[t])continue;
        dep[t]=dep[x]+1;
        dfs2(t,x);
    }
}
int main()
{
    int n=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
        ++du[u];
        ++du[v];
    }
    for(int i=1;i<=n;++i)
    {
        if(du[i]==1)
        {
            dfs1(i,i,0,0);
        }
    }
    for(int i=1;i<=n;++i)l[i].fi+=r[i].fi;
    root=max_element(du+1,du+1+n)-du;
    dfs2(root,0);
    dep[root=targ]=0;
    dfs2(root,0);
    printf("%d %d\n%d %d\n",l[root].se,l[targ].se,r[root].se,r[targ].se);
}
#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3E5+10;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int head[N],nex[N<<1],to[N<<1],cnt;
int a[N],b[N],c[N];
const int p=998244353;
void add(int u,int v)
{
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
void dfs(int x,int f)
{
    a[x]=b[x]=c[x]=1;
    for(int i=head[x];i;i=nex[i])
    {
        int t=to[i];
        if(t==f)continue;
        dfs(t,x);
        a[x]=a[x]*1LL*c[t]%p;
        b[x]=b[x]*(a[t]+c[t]*2LL)%p;
        c[x]=c[x]*1LL*(b[t]+c[t])%p;
    }
    c[x]=(c[x]*1LL+b[x]-a[x])%p;
}
int main()
{
    for(int n=read();--n;)
    {
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    write((c[1]-1+p)%p,'\n');
}
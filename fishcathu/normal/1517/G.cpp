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
const int N=2010;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int head[N],nex[N<<2],to[N<<2],val[N<<2];
int n,y,z;
int dep[N],gap[N];
queue<int>q;
ll ans;
bool b;
void add(int u,int v,int w)
{
    static int cnt=1;
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
    if(w)
    {
        val[cnt]=w;
        add(v,u,0);
    }
}
void push(int x,int w)
{
    ++gap[dep[x]=w];
    q.push(x);
}
ll dfs(int x,ll flow)
{
    if(x==z)return flow;
    ll used=0;
    for(int i=head[x];i&&flow;i=nex[i])
    {
        int t=to[i];
        if(val[i]&&dep[t]==dep[x]-1)
        {
            ll k=dfs(t,min(flow,val[i]*1LL));
            val[i]-=k;
            val[i^1]+=k;
            flow-=k;
            used+=k;
        }
    }
    if(flow)
    {
        if(!--gap[dep[x]])b=1;
        ++gap[++dep[x]];
    }
	return used;
}
void ISPA()
{
    push(z,1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=nex[i])
        {
            int t=to[i];
            if(!dep[t])push(t,dep[x]+1);
        }
    }
    while(!b)ans-=dfs(y,1LL<<60);
}
struct st
{
    int u,v,w;
    bool operator<(const st m)const
    {
        if(u!=m.u)return u<m.u;
        return v<m.v;
    }
}a[N>>1];
int getop(int l,int r)
{
    l&=1;
    r&=1;
    return r<<1|l==r;
}
void check(int u,st x)
{
    int v=lower_bound(a+1,a+1+n,x)-a;
    if(a[v].u==x.u&&a[v].v==x.v)add(u,v,inf);
}
int main()
{
    n=read();
    y=n<<1|1;
    z=y+1;
    for(int i=1;i<=n;++i)
    {
        a[i].u=read();
        a[i].v=read();
        ans+=a[i].w=read();
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        int j=i+n;
        add(i,j,a[i].w);
        int op=getop(a[i].u,a[i].v);
        if(op==3)add(j,z,inf);
        else
        {
            if(!op)add(y,i,inf);
            if(op==1)
            {
                check(j,{a[i].u,a[i].v+1});
                check(j,{a[i].u,a[i].v-1});
            }
            else
            {
                check(j,{a[i].u+1,a[i].v});
                check(j,{a[i].u-1,a[i].v});
            }
        }
    }
    ISPA();
    write(ans,'\n');
}
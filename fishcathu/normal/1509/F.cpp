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
vector<int>vc[N];
struct st
{
    int u,v,w;
    bool operator<(const st m)const
    {
        return w<m.w;
    }
}a[N];
queue<pii>q;
int fa[N],y[N];
bitset<N>b;
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    int n=read(),m=read(),z=0;
    for(int i=1;i<=m;++i)
    {
        a[i].u=read();
        a[i].v=read();
        z^=a[i].w=read();
        vc[a[i].u].pb(a[i].v);
        vc[a[i].v].pb(a[i].u);
    }
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        q.push(mp(i,1));
    }
    for(int i=1;i<=n;++i)
    {
        for(int &x:vc[i])++y[x=find(x)];
        int f=find(i),s=0;
        for(int j=q.size();j--;)
        {
            pii x=q.front();
            q.pop();
            int u=x.fi,v=x.se;
            if(u==f||v!=y[u])
            {
                fa[u]=f;
                s+=v;
            }
            else q.push(x);
        }
        q.push(mp(f,s));
        for(int x:vc[i])--y[x];
    }
    sort(a+1,a+1+m);
    ll ans=0,res=n*1LL*(n-1)/2-m-n+1;
    for(int i=1;i<=m;++i)
    {
        int u=find(a[i].u),v=find(a[i].v);
        if(u!=v)
        {
            fa[u]=v;
            b[i]=1;
            ans+=a[i].w;
            ++res;
        }
    }
    if(!res)
    {
        ans+=z;
        for(int i=1;i<=n;++i)fa[i]=i;
        for(int i=1;i<=m;++i)
        {
            if(b[i])
            {
                fa[find(a[i].u)]=find(a[i].v);
            }
        }
        for(int i=1;i<=m&&a[i].w<z;++i)
        {
            if(!b[i])
            {
                int u=find(a[i].u),v=find(a[i].v);
                if(u!=v)
                {
                    ans-=z-a[i].w;
                    break;
                }
            }
        }
    }
    write(ans,'\n');
}
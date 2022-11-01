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
const int M=16,N=1<<M;
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
#define ins(x) q.push(x),vis[x]=1
int a[N],c[N],col[N];
vct to[N];
queue<int>q;
bitset<N>b,vis;
void solve()
{
    int m=read(),n=1<<m;
    for(int i=0;i<n;++i)to[i].clear(),a[i]=b[i]=vis[i]=0;
    for(int i=n*m>>1;i--;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    b[0]=1;
    for(int i=0;i<m;++i)a[to[0][i]]=1<<i,ins(to[0][i]);
    while(!q.empty())
    {
        int x=q.front();
        b[x]=1;
        q.pop();
        for(int t:to[x])
        {
            if(b[t])continue;
            a[t]|=a[x];
            if(!vis[t])ins(t);
        }
    }
    for(int i=0;i<n;++i)c[a[i]]=i;
    for(int i=0;i<n;++i)write(c[i],' ');
    putchar('\n');
    if(__builtin_popcount(m)^1)puts("-1");
    else
    {
        for(int i=0;i<n;++i)write(col[a[i]],' ');
        putchar('\n');
    }
}
int main()
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if(i&1<<j)
            {
                col[i]^=j;
            }
        }
    }
    for(int x=read();x--;)
    {
        solve();
    }
}
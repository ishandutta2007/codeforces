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
const int N=110;
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
const int p=1E9+7;
vct to[N],g[N];
int sum[N],f[N];
void dfs(int x,int f,int d)
{
    ++sum[d];
    for(int t:to[x])
    {
        if(t^f)
        {
            dfs(t,x,d+1);
        }
    }
}
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)to[i].clear();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    if(m==2)
    {
        write(n*(n-1)>>1,'\n');
        return;
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int t:to[i])
        {
            dfs(t,i,1);
            for(int j=1;sum[j];++j)
            {
                g[j].pb(sum[j]);
                sum[j]=0;
            }
        }
        for(int j=1;!g[j].empty();g[j++].clear())
        {
            if(g[j].size()<m)continue;
            for(int x:g[j])
            {
                for(int k=m;k>=1;--k)
                {
                    f[k]=(f[k]+f[k-1]*1LL*x)%p;
                }
            }
            ans=(ans+f[m])%p;
            for(int k=1;k<=m;++k)f[k]=0;
        }
    }
    write(ans,'\n');
}
int main()
{
    f[0]=1;
    for(int x=read();x--;)
    {
        solve();
    }
}
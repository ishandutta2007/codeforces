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
const int N=210;
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
vct to[N];
int q[N],siz[N],*pos[N],*cnt;
int g[N][N],dep[N],ans;
void dfs(int x,int f)
{
    *(pos[x]=++cnt)=x;
    siz[x]=1;
    for(int t:to[x])
    {
        if(t==f)continue;
        dep[t]=dep[x]+1;
        dfs(t,x);
        for(int i=0;i<siz[x];++i)
        {
            for(int j=0;j<siz[t];++j)
            {
                int u=pos[x][i],v=pos[t][j];
                if(u>v)swap(u,v);
                ans=(ans+g[dep[u]-dep[x]][dep[v]-dep[x]])%p;
            }
        }
        siz[x]+=siz[t];
    }
}
int main()
{
    int n=read();
    for(int i=1,k=p+1>>1;i<=n;++i)
    {
        g[i][0]=1;
        for(int j=1;j<=n;++j)
        {
            g[i][j]=(g[i][j-1]+g[i-1][j])*1LL*k%p;
        }
    }
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    for(int k=1;k<=n;++k)
    {
        cnt=q;
        dep[k]=0;
        dfs(k,0);
    }
    for(int i=p-2,k=n;i;i>>=1)
    {
        if(i&1)ans=ans*1LL*k%p;
        k=k*1LL*k%p;
    }
    write(ans,'\n');
}
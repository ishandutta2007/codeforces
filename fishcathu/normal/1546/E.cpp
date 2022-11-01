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
const int N=1010,M=510;
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
const int p=998244353;
int a[N][M],b[M][M],ans[M];
bitset<N>vis;
void solve()
{
    int m=read(),n=m<<1;
    for(int i=1;i<=n;++i)
    {
        vis[i]=0;
        for(int j=1;j<=m;++j)
        {
            ++b[j][a[i][j]=read()];
        }
    }
    int s=1;
    for(int k=1;k<=m;++k)
    {
        int i=1;
        while(i<=n)
        {
            if(!vis[i])
            {
                int j=1;
                while(j<=m&&b[j][a[i][j]]^1)++j;
                if(j<=m)break;
            }
            ++i;
        }
        if(i>n)
        {
            s=s*2%p;
            while(vis[--i]);
        }
        ans[k]=i;
        for(int u=1;u<=n;++u)
        {
            if(vis[u])continue;
            int j=1;
            while(j<=m&&a[u][j]^a[i][j])++j;
            if(j>m)continue;
            vis[u]=1;
            for(int v=1;v<=m;++v)--b[v][a[u][v]];
        }
    }
    write(s,'\n');
    for(int i=1;i<=m;++i)write(ans[i],' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=3010;
int n,m,c[N][N],dd[N],l[N],d[N],f[N],ans=N;
vector<int> ke[N];
void DFS(int u,int p,int r)
{
    forv(v,ke[u]) if(v!=p)
    {
        if(c[u][v]) f[r]++;
        DFS(v,u,r);
    }
}
void DFS(int u,int p,int x,int r)
{
    ans=min(ans,l[x]+(d[u]-d[x])-(l[u]-l[x])+f[r]-l[u]);
    forv(v,ke[u]) if(v!=p)
    {
        l[v]=l[u]+(c[u][v]>0);
        d[v]=d[u]+1;
        int _x=x;
        if((d[v]-d[x])>=2*(l[v]-l[x])) _x=v;
        DFS(v,u,_x,r);
    }
}
int main()
{
    //freopen("238C.inp","r",stdin);
    n=in;
    forinc(i,1,n-1)
    {
        int u=in,v=in;
        c[v][u]=i;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    forinc(i,1,n) DFS(i,0,i);
    forinc(i,1,n)
    {
        reset(l,0);
        reset(d,0);
        DFS(i,0,i,i);
    }
    cout<<ans<<"\n";
}
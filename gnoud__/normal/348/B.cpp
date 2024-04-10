#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
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
const int N=100010,INF=1e18;
int n,d[N],f[N],c[N],a[N],dd[N],ans,tot;
vector<int> ke[N];
int lcm(int x,int y)
{
    if(x/__gcd(x,y)>INF/y) {cout<<tot;exit(0);}
    return x/__gcd(x,y)*y;
}
void DFS(int u)
{
    dd[u]=1;
    int s=0,M=1e17;
    d[u]=1;c[u]=a[u];
    forv(v,ke[u]) if(!dd[v])
    {
        ++s;
        DFS(v);
        c[u]+=c[v];
        d[u]=lcm(d[u],d[v]);
        f[u]+=f[v];
        M=min(M,c[v]);
    }
    if(s)
    {
        if(d[u]>INF/s) {cout<<tot;exit(0);}
        M=M/d[u]*d[u];
        ans+=c[u]-M*s;
        c[u]=M*s;
        d[u]*=s;
    }
    else if(!a[u]) {cout<<tot;exit(0);}
}
main()
{
    //freopen("348B.inp","r",stdin);
    n=in;
    forinc(i,1,n) a[i]=in,tot+=a[i];
    forinc(i,1,n-1)
    {
        int u=in,v=in;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    DFS(1);
    cout<<ans<<"\n";
}
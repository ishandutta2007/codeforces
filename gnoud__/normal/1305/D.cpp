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
const int N=1010;
int n,dd[N],tr[N],ma,r;
vector<int> ke[N];
void DFS(int u,int p,int l)
{
    if(l>ma) ma=l,r=u;
    forv(v,ke[u]) if(v!=p&&!dd[v])
    {
        tr[v]=u;
        DFS(v,u,l+1);
    }
}
int main()
{
    //freopen("1305D.inp","r",stdin);
    //freopen("1305D.out","w",stdout);
    cin>>n;
    forinc(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    r=1;
    while(1)
    {
        ma=0;
        DFS(r,0,0);
        reset(tr,0);
        ma=0;
        DFS(r,0,0);
        vector<int> e;
        int u=r;
        e.pb(r);
        while(tr[r]) e.pb(tr[r]),r=tr[r];
        cout<<"?"<<" "<<u<<" "<<r<<"\n";
        cin>>r;
        forv(x,e) if(x!=r) dd[x]=1;
        bool ok=1;
        forv(x,ke[r]) if(!dd[x]) ok=0;
        if(ok) return cout<<"!"<<" "<<r<<endl,0;
    }
}
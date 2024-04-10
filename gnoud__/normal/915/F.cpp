#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
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
const int N=1000010;
int n,id[N],dd[N];
pii a[N];
vector<int> ke[N];
int r(int x){return id[x]<0?x:id[x]=r(id[x]);}
void unions(int u,int v)
{
    if((u=r(u))==(v=r(v))) return;
    if(id[u]<id[v]) swap(u,v);
    id[u]+=id[v];
    id[v]=u;
}
int Sol(int o)
{
    reset(id,-1);
    sort(a+1,a+n+1);
    if(o==-1) reverse(a+1,a+n+1);
    forinc(i,1,n) dd[a[i].se]=i;
    int ret=0;
    forinc(i,1,n)
    {
        int u=a[i].se,T=1;
        forv(v,ke[u]) if(dd[v]<dd[u])
        {
            ret-=id[r(v)]*T*a[i].fi;
            T-=id[r(v)];
            unions(u,v);
        }
    }
    return ret;
}
main()
{
    //freopen("915F.inp","r",stdin);
    n=in;
    forinc(i,1,n) a[i]={in,i};
    forinc(i,1,n-1)
    {
        int u=in,v=in;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    cout<<Sol(1)-Sol(-1)<<"\n";
}
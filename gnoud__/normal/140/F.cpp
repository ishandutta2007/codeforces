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
const int N=200010;
int n,k;
pii a[N];
vector<pii> ans;
void sol(int u,int v)
{
    pii s={(a[u].fi+a[v].fi)/2,(a[u].se+a[v].se)/2};
    int j=n,res=0;
    forinc(i,1,n)
    {
        pii p={s.fi*2-a[i].fi,s.se*2-a[i].se};
        while(j&&a[j].fi>p.fi||(a[j].fi==p.fi&&a[j].se>p.se)) --j;
        if(!j||a[j]!=p) ++res;
    }
    if(res<=k) ans.pb(s);
}
main()
{
    //freopen("140F.inp","r",stdin);
    //freopen("140F.out","w",stdout);
    cout<<setprecision(2)<<fixed;
    n=in,k=in;
    if(k>=n) return cout<<-1,0;
    forinc(i,1,n) a[i]={in*2,in*2};
    sort(a+1,a+n+1);
    forinc(i,1,min(n,k+1)) fordec(j,n,max(1ll,n-k)) sol(i,j);
    sort(all(ans));
    ans.erase(unique(all(ans)),ans.end());
    cout<<ans.size()<<"\n";
    forv(x,ans) cout<<0.5*x.fi<<" "<<0.5*x.se<<"\n";
}
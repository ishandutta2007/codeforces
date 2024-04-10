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
const int N=2e6+10;
int n,a[N],p[N],f[N];
vector<pii> e;
vector<int> nt;
main()
{
    //freopen("1305F.inp","r",stdin);
    srand(time(NULL));
    n=in;
    forinc(i,2,N-10) if(!p[i])
    for(int j=i;j<=N-10;j+=i) p[j]=i;
    int mx=0;
    forinc(i,1,n) a[i]=in,mx=max(mx,a[i]);
    int l=max(1ll,mx-n),r=mx+n;
    forinc(i,l,r) f[i-l]=i;
    forinc(i,2,N-10) if(p[i]==i)
    for(int j=((l-1)/i+1)*i;j<=r;j+=i)
    {
        nt.pb(i);
        while(f[j-l]%i==0) f[j-l]/=i;
    }
    forinc(i,l,r) if(f[i-l]!=1) nt.pb(f[i-l]);
    sort(all(nt));
    nt.erase(unique(all(nt)),nt.end());
    int ans=n;
    random_shuffle(a+1,a+n+1);
    forv(x,nt)
    {
        int ret=0;
        forinc(i,1,n)
        {
            int L=(a[i]/x)*x,R=L+x;
            int mi=R-a[i];
            if(L) mi=min(mi,a[i]-L);
            ret+=mi;
            if(ret>ans) break;
        }
        ans=min(ans,ret);
    }
    cout<<ans<<"\n";
}
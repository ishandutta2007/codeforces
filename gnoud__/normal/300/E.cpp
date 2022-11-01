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
const int N=1e7+10;
int n,a[N],s[N],p[N],res;
ll S(ll n,ll i)
{
    ll ret=0,x=i;
    while(x<=n)
    {
        ret+=n/x;
        x*=i;
    }
    return ret;
}
main()
{
    //freopen("300E.inp","r",stdin);
    n=in;
    forinc(i,2,N-10) if(!p[i])
    for(int j=i;j<=N-10;j+=i) p[j]=i;
    a[1]=n;
    forinc(i,1,n) a[in+1]--;
    forinc(i,2,1e7)
    {
        a[i]+=a[i-1];
        int x=i;
        while(x!=1)
        {
            s[p[x]]+=a[i];
            x/=p[x];
        }
    }
    ll ans=1;
    forinc(i,2,1e7) if(s[i])
    {
        ll l=1,r=1e13,o;
        while(l<=r)
        {
            ll m=(l+r)/2;
            if(S(m,i)>=s[i]) o=m,r=m-1;
            else l=m+1;
        }
        ans=max(ans,o);
    }
    cout<<ans<<"\n";
}
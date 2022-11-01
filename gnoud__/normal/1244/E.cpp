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
const int N=100010;
int n,k,a[N],s[N];
bool kt(int l,int r)
{
    int L=max(l,1ll),R=r;
    l=lower_bound(a+1,a+n+1,L)-a-1;
    r=upper_bound(a+1,a+n+1,R)-a-1;
    int S=L*l-s[l]+((r==n+1)?0:s[n]-s[r]-R*(n-r));
    return (S<=k);
}
bool cheq(int x)
{
    forinc(i,1,n)
    {
        if(kt(a[i],a[i]+x)) return 1;
        if(kt(a[i]-x,a[i])) return 1;
    }
    return 0;
}
main()
{
    //freopen("1244E.inp","r",stdin);
    n=in,k=in;
    forinc(i,1,n) a[i]=in;
    sort(a+1,a+n+1);
    forinc(i,1,n) s[i]=s[i-1]+a[i];
    int l=0,r=1e9,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(cheq(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<"\n";
}
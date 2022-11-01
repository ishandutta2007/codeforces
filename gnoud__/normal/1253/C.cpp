#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef unsigned long long ull;
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
const int N=2e5+5;
int n,m,a[N],sum[N];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("1253C.inp","r",stdin);
    cin>>n>>m;
    forinc(i,1,n) cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    sort(a+1,a+n+1);
    forinc(i,1,n)
    {
        sum[i]=a[i];
        if(i>m) sum[i]+=sum[i-m];
    }
    int ans=0;
    forinc(i,1,n)
    {
        ans+=sum[i];
        cout<<ans<<" ";
    }
}
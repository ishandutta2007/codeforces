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
const int N=510;
int n,m,b,f[N][N],g[N][N],a[N],mod;
int main()
{
    //freopen("543A.inp","r",stdin);
    n=in,m=in,b=in,mod=in;
    forinc(i,1,n) a[i]=in;
    f[0][0]=1;
    forinc(i,1,n) forinc(j,1,m) forinc(k,a[i],b) f[j][k]=(f[j][k]+f[j-1][k-a[i]])%mod;
    int ans=0;
    forinc(i,0,b) ans=(ans+f[m][i])%mod;
    cout<<ans<<"\n";
}
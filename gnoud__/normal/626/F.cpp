#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
const int N=205,mod=1e9+7;
int n,k,a[N],b[N],f[N][N/2][5*N];
int F(int i,int j,int s)
{
    if(j>n-i+1||s>k) return 0;
    if(i==n+1) return (!j);
    if(f[i][j][s]!=-1) return f[i][j][s];
    int &ret=f[i][j][s];
    int _s=s+b[i]*j;
    ret=(F(i+1,j+1,_s)+F(i+1,j,_s))%mod;
    if(j)
    {
        ret=(ret+1ll*j*F(i+1,j,_s)%mod)%mod;
        ret=(ret+1ll*j*F(i+1,j-1,_s)%mod)%mod;
    }
    return ret;
}
int main()
{
    //freopen("626F.inp","r",stdin);
    n=in,k=in;
    forinc(i,1,n) a[i]=in;
    sort(a+1,a+n+1);
    forinc(i,1,n) b[i]=a[i]-a[i-1];
    reset(f,-1);
    cout<<F(1,0,0)<<"\n";
}
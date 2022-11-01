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
const int N=5010;
int n,m,mod,l[1000010],a[N][N],f[N],A[N],s[1000010],pw[N];
main()
{
    //freopen("140E.inp","r",stdin);
    n=in,m=in,mod=in;
    forinc(i,1,n) l[i]=in;
    a[0][0]=1;
    forinc(i,1,5000) forinc(j,1,i) a[i][j]=(a[i-1][j-1]+a[i-1][j]*(j-1))%mod;
    A[1]=m;
    forinc(i,2,5000) A[i]=(A[i-1]*(m-i+1))%mod;
    pw[0]=1;
    forinc(i,1,5000) pw[i]=pw[i-1]*i%mod;
    s[0]=1;
    forinc(i,1,n) forinc(j,1,l[i])
    {
        if(j<=l[i-1]) f[j]=(a[l[i]][j]*(s[i-1]-f[j]*pw[j]%mod))%mod;
        else f[j]=(a[l[i]][j]*s[i-1])%mod;
        s[i]=(s[i]+f[j]*A[j])%mod;
    }
    cout<<(s[n]+mod)%mod<<"\n";
}
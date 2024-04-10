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
const int N=3e5+10;
int n,f[N][12],a[N],m,k,ans;
main()
{
    //freopen("1197D.inp","r",stdin);
    n=in,m=in,k=in;
    forinc(i,1,n) a[i]=in;
    reset(f,-100);
    forinc(i,0,n) f[i][0]=f[i][m]=0;
    forinc(i,1,n)
    {
        forinc(j,1,m)
        {
            f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]-k*(j==1));
            ans=max(ans,f[i][j]);
        }
        f[i][0]=f[i][m];
    }
    cout<<ans;
}
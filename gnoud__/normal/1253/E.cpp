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
const int N=82,M=1e5+2;
int n,m,f[N][M],s[N][M];
pii a[N];
main()
{
    //freopen("1253E.inp","r",stdin);
    //freopen("1253E.out","w",stdout);
    n=in,m=in;
    forinc(i,1,n) a[i]={in,in};
    sort(a+1,a+n+1);
    reset(f,127);reset(s,127);
    int oo=f[0][0];
    f[0][0]=0;s[0][0]=0;
    forinc(i,1,n) fordec(j,2*m,0)
    {
        int _j=min(m,j);
        f[i][_j]=min(f[i][_j],s[i-1][_j]);
        if(j>=a[i].fi) f[i][_j]=min(f[i][_j],s[i-1][max(0ll,2*a[i].fi-j-1)]+(((j-a[i].fi)<=a[i].se)?0:(j-a[i].fi-a[i].se)));
        s[i][_j]=min({s[i][_j+1],s[i][_j],f[i][_j]});
    }
    cout<<f[n][m]<<"\n";
}
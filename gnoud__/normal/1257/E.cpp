#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int N=200010;
int n,a[N],m[3],f[N][10];
int main()
{
    //freopen("1257E.inp","r",stdin);
    m[0]=in,m[1]=in,m[2]=in;
    forinc(i,1,m[0]) a[in]=0;
    forinc(i,1,m[1]) a[in]=1;
    forinc(i,1,m[2]) a[in]=2;
    n=m[0]+m[1]+m[2];
    f[0][0]=0;
    reset(f,127);
    f[0][0]=0;
    forinc(i,0,n-1) forinc(j,0,2)
    {
        f[i+1][j]=min(f[i+1][j],f[i][j]+(a[i+1]!=j));
        f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+(a[i+1]!=(j+1)));
        f[i+1][j+2]=min(f[i+1][j+2],f[i][j]+(a[i+1]!=(j+2)));
    }
    cout<<min({f[n][0],f[n][1],f[n][2]});
}
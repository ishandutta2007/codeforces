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
const int N=310;
int n,ans;
pii a[N];
int S(pii x,pii y,pii z)
{
    return (y.fi-x.fi)*(z.se-y.se)-(z.fi-y.fi)*(y.se-x.se);
}
int main()
{
    //freopen("340B.inp","r",stdin);
    cout<<setprecision(9)<<fixed;
	n=in;
	forinc(i,1,n) a[i]={in,in};
	forinc(i,1,n) forinc(j,i+1,n)
	{
        int mi=INT_MAX,ma=INT_MIN;
        forinc(k,1,n) if(k!=i&&k!=j)
        {
            mi=min(mi,S(a[i],a[j],a[k]));
            ma=max(ma,S(a[i],a[j],a[k]));
        }
		ans=max(ans,ma-mi);
	}
	cout<<1.0*ans/2<<"\n";
}
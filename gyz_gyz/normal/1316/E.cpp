#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18;
struct peo{
	ll a,s[7];
}a[N];
ll f[2][128];
bool cmp(const peo&x,const peo&y){
	return x.a>y.a;
}
int main(){int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	rep(i,1,n)scanf("%lld",&a[i].a);
	rep(i,1,n)rep(j,0,p-1)scanf("%lld",&a[i].s[j]);
	sort(a+1,a+n+1,cmp);int t=0;
	dep(j,(1<<p)-1,1)f[t][j]=-inf;
	rep(i,1,n){t^=1;
		dep(j,(1<<p)-1,0)f[t][j]=-inf;
		dep(j,(1<<p)-1,0){int cnt=0;
			rep(k,0,p-1)if((j>>k)&1){++cnt;
				f[t][j]=max(f[t][j],f[t^1][j^(1<<k)]+a[i].s[k]);
			}
			f[t][j]=max(f[t][j],f[t^1][j]+(cnt+k>=i?a[i].a:0));
		}
	}
	printf("%lld\n",f[t][(1<<p)-1]);
}
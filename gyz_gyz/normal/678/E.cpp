#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
double p[20][20],a[1<<18][20];
int main(){int n;double ans=0;
	scanf("%d",&n);int nn=(1<<n)-1;a[1][0]=1;
	rep(i,0,n-1)rep(j,0,n-1)scanf("%lf",&p[i][j]);
	rep(i,2,nn)rep(j,0,n-1)if(i&(1<<j))
		rep(k,0,n-1)if(j!=k&&(i&(1<<k)))
			a[i][j]=max(a[i][j],a[i-(1<<k)][j]*p[j][k]+a[i-(1<<j)][k]*p[k][j]);
	rep(i,0,n-1)ans=max(ans,a[nn][i]);
	printf("%.15lf\n",ans);
}
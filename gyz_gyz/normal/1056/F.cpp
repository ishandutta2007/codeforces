#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;double c,m,f[N][N*10],r[N];
struct pr{double a;int p;}a[N];
bool cmp(pr x,pr y){return x.a>y.a;}
void sol(){int tot=0;
	scanf("%d%lf%lf",&n,&c,&m);
	rep(i,1,n){
		scanf("%lf%d",&a[i].a,&a[i].p);
		tot+=a[i].p;
	}
	sort(a+1,a+n+1,cmp);
	rep(i,0,n)rep(j,0,tot)f[i][j]=1e18;f[0][0]=0;
	rep(i,1,n)dep(j,i,1)rep(k,a[i].p,tot)
		f[j][k]=min(f[j][k],f[j-1][k-a[i].p]+a[i].a/r[j]);
	dep(j,tot,0)rep(i,0,n)if(f[i][j]<1e18){
		double y=max(sqrt(f[i][j]*c),1.);
		double t=(y-1)/c+f[i][j]/y+10*i;
		if(t<=m){printf("%d\n",j);return;}
	}
}
int main(){int T;r[0]=1;
	rep(i,1,100)r[i]=r[i-1]*0.9;
	for(scanf("%d",&T);T;T--)sol();
}
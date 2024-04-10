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
struct mt{
	int n,m;ll a[2][2];
	mt(){memset(this,0,sizeof(mt));}
	friend mt operator *(mt a,mt b){
		mt r;r.n=a.n;r.m=b.m;
		rep(i,0,r.n-1)rep(j,0,r.m-1)rep(k,0,a.m-1)
			r.a[i][j]=(r.a[i][j]+a.a[i][k]*b.a[k][j])%mo;
		return r;
	}
}a,b;
void qk(mt&r,mt x,ll y){
	for(;y;y>>=1){
		if(y&1)r=r*x;x=x*x;
	}
}
int main(){ll A,B,n,x;
	scanf("%lld%lld%lld%lld",&A,&B,&n,&x);
	a.n=a.m=b.m=2;b.n=1;
	a.a[0][0]=A;a.a[1][1]=1;a.a[1][0]=B;
	b.a[0][0]=x;b.a[0][1]=1;
	qk(b,a,n);
	printf("%lld\n",b.a[0][0]);
}
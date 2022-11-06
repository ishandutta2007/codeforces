#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
struct mt{
	int n,m;ll a[2][2];
	mt(){memset(this,0,sizeof(mt));}
	friend mt operator *(const mt&a,const mt&b){
		mt c;c.n=a.n;c.m=b.m;
		rep(i,0,c.n-1)rep(j,0,c.m-1)rep(k,0,a.m-1)
			(c.a[i][j]+=a.a[i][k]*b.a[k][j])%=mo;
		return c;
	}
};
ll qk(ll x,ll y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
void qk(mt&r,mt x,ll y){
	for(;y;y>>=1){
		if(y&1)r=r*x;x=x*x;
	}
}
int main(){ll n,m,l,r;
	scanf("%lld%lld%lld%lld",&n,&m,&l,&r);
	if((n*m)&1)return printf("%lld\n",qk((r-l+1)%mo,n*m)),0;
	ll ji=(r-l+1)/2%mo,ou=ji;
	if(l%2==r%2){
		if(l&1)ji=(ji+1)%mo;else ou=(ou+1)%mo;
	}
	mt a,b;
	a.n=a.a[0][0]=1;a.m=b.n=b.m=2;
	b.a[0][1]=b.a[1][0]=ji;
	b.a[0][0]=b.a[1][1]=ou;
	qk(a,b,n*m);
	printf("%lld\n",a.a[0][0]);
}
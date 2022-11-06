#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int mo=1e9+7;
struct mt{
	ll a[3][3];
	ll* operator [](int x){return a[x];}
	const ll* operator [](int x)const{return a[x];}
	friend mt operator *(const mt&a,const mt&b){mt c;
		rep(i,0,2)rep(j,0,2)c[i][j]=(a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j])%(mo-1);
		return c;
	}
};
mt qk(mt r,mt x,ll n){
	for(;n;n>>=1){
		if(n&1)r=r*x;x=x*x;
	}return r;
}
ll qk(ll x,ll n){ll r=1;
	for(;n;n>>=1){
		if(n&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){ll n,f1,f2,f3,c;
	scanf("%lld%lld%lld%lld%lld",&n,&f1,&f2,&f3,&c);
	f1=f1*c%mo;f2=f2*c%mo*c%mo;f3=f3*c%mo*c%mo*c%mo;
	mt res=qk({{{1,0,0},{0,1,0},{0,0,1}}},{{{1,1,0},{1,0,1},{1,0,0}}},n-3);
	ll fn=qk(f1,res[2][0])*qk(f2,res[1][0])%mo*qk(f3,res[0][0])%mo;
	printf("%lld\n",fn*qk(qk(c,n),mo-2)%mo);
}
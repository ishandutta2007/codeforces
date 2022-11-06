#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
const int mo=998244353;
ll f[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll c(int x,int y){
	return f[x]*qk(f[y],mo-2)%mo*qk(f[x-y],mo-2)%mo;
}
int main(){int n,m;
	scanf("%d%d",&n,&m);f[0]=1;
	rep(i,1,m)f[i]=f[i-1]*i%mo;
	printf("%lld\n",n==2?0ll:(n-2)*c(m,n-1)%mo*qk(2,n-3)%mo);
}
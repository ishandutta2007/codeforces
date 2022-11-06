#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
int a[N];ll p[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll c(int n,int m){
	return p[n]*qk(p[m],mo-2)%mo*qk(p[n-m],mo-2)%mo;
}
int main(){
	int n,m=0;ll k,ans=1;p[0]=1;
	scanf("%d%lld",&n,&k);
	rep(i,1,n)p[i]=p[i-1]*i%mo;
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)if(a[i%n+1]!=a[i]){
		++m;ans=ans*k%mo;
	}
	rep(i,0,m/2)ans=(ans+mo-c(m,i)*c(m-i,i)%mo*qk(k-2,m-i*2)%mo)%mo;
	ans=ans*qk(2,mo-2)%mo;
	rep(i,m+1,n)ans=ans*k%mo;
	printf("%lld\n",ans);
}
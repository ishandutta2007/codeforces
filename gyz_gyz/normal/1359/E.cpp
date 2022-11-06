#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
ll a[N],p[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll c(int x,int y){
	return p[x]*qk(p[y],mo-2)%mo*qk(p[x-y],mo-2)%mo;
}
int main(){int n,k;ll ans=0;
	scanf("%d%d",&n,&k);p[0]=1;
	rep(i,1,n+k)p[i]=p[i-1]*i%mo;
	dep(i,n/k,1)ans=(ans+c(n/i-1,k-1))%mo;
	printf("%lld\n",ans);
}
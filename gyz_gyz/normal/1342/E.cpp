#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const ll inf=1e18;
const int mo=998244353;
ll f[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll cal(int n,int m){ll ans=0;
	rep(k,0,m){
		ll res=qk(m-k,n)*qk(f[k]*f[m-k]%mo,mo-2)%mo;
		if(k&1)ans=(ans+mo-res)%mo;
		else ans=(ans+res)%mo;
	}return ans;
}
int main(){int n,k;
	scanf("%d%d",&n,&k);f[0]=1;
	rep(i,1,n)f[i]=f[i-1]*i%mo;
	if(!k)return printf("%lld\n",f[n]),0;
	if(k>n-1)return printf("0\n"),0;
	printf("%lld\n",cal(n,n-k)*f[n]%mo*qk(f[k],mo-2)%mo*2%mo);
}
#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e6+10;
const int mo=998244353;
ll p[N],r[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){int n;ll ans=0;
	scanf("%d",&n);
	rep(i,1,n){int m;
		scanf("%d",&m);
		rep(i,1,m){
			int x;scanf("%d",&x);
			p[x]=(p[x]+qk(n,mo-2)*qk(m,mo-2))%mo;
			r[x]=(r[x]+qk(n,mo-2))%mo;
		}
	}
	rep(i,1,1000000)ans=(ans+p[i]*r[i])%mo;
	printf("%lld\n",ans);
}
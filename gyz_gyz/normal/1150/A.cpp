#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=1e7;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
int main(){int n,m;ll k;
	scanf("%d%d%lld",&n,&m,&k);
	int mi=inf,mx=0;
	rep(i,1,n){int x;
		scanf("%d",&x);
		mi=min(x,mi);
	}
	rep(i,1,m){int x;
		scanf("%d",&x);
		mx=max(x,mx);
	}
	if(mx>mi){
		ll x=k/mi;
		k+=x*(mx-mi);
	}
	printf("%lld\n",k);
}
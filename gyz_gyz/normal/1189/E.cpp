#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
int main(){int n;ll p,k,ans=0;
	map<ll,int>r;
	scanf("%d%lld%lld",&n,&p,&k);
	rep(i,1,n){ll x;
		scanf("%lld",&x);
		ll s=(x*x%p*x%p*x%p+p-k*x%p)%p;
		ans+=r[s]++;
	}
	printf("%lld\n",ans);
}
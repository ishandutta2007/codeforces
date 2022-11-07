#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll inf=1e18;
const int mo=998244353;
void sol(){
	int n;ll s=-inf,ans=0;
	scanf("%d",&n);
	rep(i,1,n){ll x;
		scanf("%lld",&x);
		s=max(s,x);
		ans=max(ans,s-x);
	}int ct=0;
	for(;ans;ans>>=1)++ct;
	printf("%d\n",ct);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}
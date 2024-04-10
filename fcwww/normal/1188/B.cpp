#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define N 300050
int n;
pl a[N];
ll K,p;
ll C2(ll x) {
	return x*(x-1)/2;
}
ll qp4(ll x) {
	return x*x%p*x%p*x%p;
}
ll get_v(int s) {
	return ((a[s].first * K - a[s].second)%p+p)%p;
}

map<ll,ll>mp;

int main() {
	scanf("%d%lld%lld",&n,&p,&K);
	int i;
	for(i=1;i<=n;i++) scanf("%lld",&a[i].first),a[i].second=qp4(a[i].first);
	for(i=1;i<=n;i++) mp[get_v(i)]++;

	map<ll,ll>::iterator uu;
	ll ans=0;
	for(uu=mp.begin();uu!=mp.end();uu++) {
		ans+=C2(uu->second);
	}
	printf("%lld\n",ans);
}
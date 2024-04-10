#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	vector<ll> head;
	vector<ll> tail;
	ll h = n / 2, t = n - n / 2;
	REP(bit, (1ll << h)) {
		bitset<18> bi(bit);
		ll sum = 0;
		REP(i, h) {
			if(bi[i]) sum += a[i];
		}
		sum %= m;
		head.pb(sum);
	}
	REP(bit, (1ll << t)) {
		bitset<18> bi(bit);
		ll sum = 0;
		REP(i, t) {
			if(bi[i]) sum += a[h + i];
		}
		sum %= m;
		tail.pb(sum);
	}
	UNIQUE(head);
	UNIQUE(tail);
	ll ans = 0;
	REP(i, head.size()) ans = max(ans, head[i]);
	REP(i, tail.size()) ans = max(ans, tail[i]);
	REP(i, head.size()) {
		ans = max(ans, (head[i] + tail[(ll)tail.size() - 1]) % m);
		auto lb = lower_bound(ALL(tail), m - head[i]);
		if(lb == tail.begin()) continue;
		lb--;
		ans = max(ans, (head[i] + *lb) % m);
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */
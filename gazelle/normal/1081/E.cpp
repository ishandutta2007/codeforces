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
#define MOD 998244353LL
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
	ll n;
	cin >> n;
	vector<ll> ans(n, 0);
	REP(i, n / 2) {
		cin >> ans[2 * i + 1];
	}
	ll tmp = 0;
	REP(i, n / 2) {
		ll lb = INF * INF;
		for(ll j = 1; j * j <= ans[2 * i + 1]; j++) {
			if(ans[2 * i + 1] % j) continue;
			ll a = j, b = ans[2 * i + 1] / j;
			if(a % 2 != b % 2) continue;
			ll x = (b + a) / 2, y = (b - a) / 2;
			if(y <= tmp) continue;
			lb = min(lb, x);
		}
		if(lb == INF * INF) {
			cout << "No" << endl;
			return 0;
		}
		ans[2 * i] = lb * lb - ans[2 * i + 1] - tmp * tmp;
		tmp = lb;
	}
	cout << "Yes" << endl;
	DUMP(ans);
	return 0;
}

/* --------------------------------------- */
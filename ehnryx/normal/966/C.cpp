#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	os << "[ "; for (const T& it : v) os << it << " "; return os << "]";
}

vector<ll> vals[64];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	ll b;
	ll start = 0;
	for (int i = 0; i < n; i++) {
		cin >> b;
		start ^= b;
		vals[63-__builtin_clzll(b)].push_back(b);
	}

	while (clock() < 1.9*CLOCKS_PER_SEC) {
		// sort
		for (int i = 0; i < 64; i++) {
			shuffle(vals[i].begin(), vals[i].end(), rng);
		}

		// greedy???
		bool bad = false;
		vector<ll> ans;
		ll cur = start;
		for (int i = 0; i < n; i++) {
			bad = true;
			for (int j = 0; j < 64; j++) {
				if ((cur & 1LL<<j) && !vals[j].empty()) {
					ans.push_back(vals[j].back());
					cur ^= vals[j].back();
					vals[j].pop_back();
					bad = false;
					break;
				}
			}
			if (bad) break;
		}
		if (bad) continue;

		reverse(ans.begin(), ans.end());
		cout << "Yes" << nl;
		for (ll it : ans) cout << it << " ";
		cout << nl;
		return 0;
	}

	cout << "No" << nl;

	return 0;
}
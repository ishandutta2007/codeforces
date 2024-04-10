//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class T> ostream& operator << (ostream& os, const vector<T>& v) {
	os << "[ ";
	for(T it : v) os << it << " ";
	return os << "]";
}

const int CAP = 2e5;

void output(vector<ll>& ans) {
	ll prefs = accumulate(ans.begin(), ans.end(), (ll)0, [](ll c, ll v) {
		return c + max(v, (ll)0);
	});

	if(prefs > CAP) {
		cout << "BIG" << nl;
		cout << prefs << nl;
	} else {
		cout << "SMALL" << nl;
		reverse(ans.begin(), ans.end());
		ll sum = accumulate(ans.begin(), ans.end(), (ll)0, [](ll c, ll v) {
			return c + abs(v);
		});
		cout << sum << nl;
		for(ll it : ans) {
			if(it == -1) {
				cout << 'R';
			} else {
				for(int i=0; i<it; i++) {
					cout << 'P';
				}
			}
		}
		cout << nl;
	}
}

void solve_two(vector<ll> a, vector<ll> b) {
	bool rev = false;
	vector<ll> ans = {0};
	if(a[0] > a[1]) {
		rev = true;
		swap(a[0], a[1]);
		swap(b[0], b[1]);
		ans.push_back(-1);
	}
	while(a[0] < b[0]) {
		if(b[0] > b[1]) {
			swap(b[0], b[1]);
			if(ans.back() == -1) ans.pop_back();
			else ans.push_back(-1);
		}
		if(a[0] < b[0]) {
			ans.push_back(b[1] / b[0]);
			b[1] %= b[0];
		}
	}

	if(a[0] == b[0] && b[1] >= a[1] && (b[1]-a[1]) % b[0] == 0) {
		ans.push_back((b[1]-a[1]) / b[0]);
		if(rev) {
			if(ans.back() == -1) ans.pop_back();
			else ans.push_back(-1);
		}
	} else {
		cout << "IMPOSSIBLE" << nl;
		return;
	}

	output(ans);
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<n; i++) {
		cin >> b[i];
	}

	if(n == 1) {
		if(a == b) {
			cout << "SMALL" << nl;
			cout << 0 << nl;
			cout << nl;
		} else {
			cout << "IMPOSSIBLE" << nl;
		}
		return 0;
	}

	if(n == 2) {
		solve_two(a, b);
		return 0;
	}

	vector<ll> ans;

	vector<ll> reva = a;
	reverse(reva.begin(), reva.end());
	ll minv = *min_element(a.begin(), a.end());

	while(b != a && b != reva) {
		if(b[0] > b[1]) {
			ans.push_back(-1);
			reverse(b.begin(), b.end());
		}
		adjacent_difference(b.begin(), b.end(), b.begin());
		ans.push_back(1);
		if(*min_element(b.begin(), b.end()) < minv) {
			cout << "IMPOSSIBLE" << nl;
			return 0;
		}
	}
	if(b == reva) {
		ans.push_back(-1);
	}

	output(ans);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> factors(int n) {
	vector<int> ret;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			ret.push_back(i);
			if (n/i != i && i != 1) {
				ret.push_back(n/i);
			}
		}
	}
	vector<int> new_ret;
	rep(i,0,sz(ret)) {
		bool ok = true;
		rep(j,0,sz(ret)) {
			if (ret[j] != ret[i] && ret[j]%ret[i] == 0)
				ok = 0;
		}
		if (ok)
			new_ret.push_back(ret[i]);
	}
	return new_ret;
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	rep(i,0,n)
		cin >> a[i];
	auto F = factors(n);
	vector<vector<ll>> sums;
	map<ll, int> M;
	for (int f : F) {
		sums.emplace_back();
		rep(i,0,f) {
			ll s = 0;
			rep(j,0,n/f) {
				s += a[i+j*f];
			}
			s *= f;
			sums.back().push_back(s);
			M[s]++;
		}
	}
	cout << M.rbegin()->first << endl;
	while (q--) {
		int p;
		ll x;
		cin >> p >> x;
		--p;
		rep(fi,0,sz(F)) {
			int f = F[fi];
			int i = p%f;
			ll s = sums[fi][i];
			int new_val = --M[s];
			if (!new_val)
				M.erase(s);
			s += (x - a[p])*f;
			sums[fi][i] = s;
			++M[s];
		}
		a[p] = x;
		cout << M.rbegin()->first << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}
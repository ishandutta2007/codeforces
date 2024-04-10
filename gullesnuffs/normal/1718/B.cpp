#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> fib;

bool solve(map<ll, int>& c, int i, ll forbidden) {
	if (i == -1) {
		return true;
	}
	set<ll> T;
	for (auto it = c.rbegin(); it != c.rend(); ++it) {
		if (it->first >= fib[i] && it->second >= 1+(forbidden == it->first)) {
			T.insert(it->first);			
		}
	}
	for (ll t : T) {
		--c[t];
		if (!c[t])
			c.erase(t);
		++c[t-fib[i]];
		if (solve(c, i-1, t-fib[i])) {
			return true;
		}
		--c[t-fib[i]];
		if (!c[t-fib[i]])
			c.erase(t-fib[i]);
		++c[t];
	}
	return false;
}

void solve() {
	int k;
	cin >> k;
	vector<ll> c(k);
	ll sum = 0;
	rep(i,0,k) {
		cin >> c[i];
		sum += c[i];
	}
	ll s2 = 0;
	int i;
	for (i=0; s2 < sum; i++) {
		s2 += fib[i];
	}
	--i;
	if (s2 != sum) {
		cout << "NO" << endl;
		return;
	}
	map<ll, int> C;
	rep(i,0,k)
		C[c[i]]++;
	if (solve(C, i, -1)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	fib.push_back(1);
	fib.push_back(1);
	while (fib.back() < 1e12) {
		fib.push_back(fib[sz(fib)-2]+fib[sz(fib)-1]);
	}
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}
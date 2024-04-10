#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pair<int, pair<int, int>>, ll> cache;

ll solve(const vector<int>& a, const vector<int>& b, int i, int lastA, int lastB) {
	auto key = make_pair(i, make_pair(lastA, lastB));
	if (cache.count(key))
		return cache[key];
	if (i == sz(a))
		return 0;
	ll res = abs(a[i]-lastA)+abs(b[i]-lastB)+solve(a, b, i+1, a[i], b[i]);
	res = min(res, abs(b[i]-lastA)+abs(a[i]-lastB)+solve(a, b, i+1, b[i], a[i]));
	cache[key] = res;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i,0,n)
		cin >> a[i];
	rep(i,0,n)
		cin >> b[i];
	cache.clear();
	cout << solve(a, b, 1, a[0], b[0]) << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}
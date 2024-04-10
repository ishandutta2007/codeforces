#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////
// Extended Euclidean Algorithm (UBC)
// egcd(a,b,x,y) calculates x,y such that ax+by=gcd(a,b)
// To find a^{-1} mod m, use egcd(a,m,x,y) and x = a^{-1}
// Returns gcd(a,b)
ll egcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	} else {
		ll d = egcd(b, a%b, y, x);
		y -= x * (a/b);
		return d;
	}
}
//*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int u, v, p;
	cin >> u >> v >> p;

	if (u == v) {
		cout << 0 << nl;
		return 0;
	}

	auto next = [&] (int n) {
		return n+1 == p ? 0 : n+1;
	};
	auto prev = [&] (int n) {
		return n-1 < 0 ? p-1 : n-1;
	};
	auto inv = [&] (int n) {
		if (n == 0) return 0;
		ll x, y;
		egcd(n, p, x, y);
		return (int) (x < 0 ? x+p : x);
	};

	unordered_map<int,pii> par, rpar;
	unordered_set<int> lvis, rvis;
	lvis.insert(u);
	rvis.insert(v);

	int cur;
	int mid = -1;

	queue<int> lq, rq;
	lq.push(u);
	rq.push(v);
	while (!lq.empty() || !rq.empty()) {
		// left
		if (!lq.empty()) {
			cur = lq.front(); lq.pop();
			// 1
			mid = next(cur);
			if (!lvis.count(mid)) {
				lvis.insert(mid);
				par[mid] = pii(cur, 1);
				if (rvis.count(mid)) break;
				else lq.push(mid);
			}
			// 2
			mid = prev(cur);
			if (!lvis.count(mid)) {
				lvis.insert(mid);
				par[mid] = pii(cur, 2);
				if (rvis.count(mid)) break;
				else lq.push(mid);
			}
			// 3
			mid = inv(cur);
			if (!lvis.count(mid)) {
				lvis.insert(mid);
				par[mid] = pii(cur, 3);
				if (rvis.count(mid)) break;
				else lq.push(mid);
			}
		}

		// right
		if (!rq.empty()) {
			cur = rq.front(); rq.pop();
			// 1
			mid = next(cur);
			if (!rvis.count(mid)) {
				rvis.insert(mid);
				rpar[mid] = pii(cur, 2);
				if (lvis.count(mid)) break;
				else rq.push(mid);
			}
			// 2
			mid = prev(cur);
			if (!rvis.count(mid)) {
				rvis.insert(mid);
				rpar[mid] = pii(cur, 1);
				if (lvis.count(mid)) break;
				else rq.push(mid);
			}
			// 3
			mid = inv(cur);
			if (!rvis.count(mid)) {
				rvis.insert(mid);
				rpar[mid] = pii(cur, 3);
				if (lvis.count(mid)) break;
				else rq.push(mid);
			}
		}
	}
	cerr << "mid: " << mid << nl;
	assert(mid == u || par.count(mid));
	assert(mid == v || rpar.count(mid));

	vector<int> ans;
	for (int i = mid; i != u; i = par[i].first) {
		ans.push_back(par[i].second);
	}
	reverse(ans.begin(), ans.end());
	for (int i = mid; i != v; i = rpar[i].first) {
		ans.push_back(rpar[i].second);
	}

	cout << ans.size() << nl;
	for (int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}
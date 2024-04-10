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
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////
// Int struct for operations on a prime field (TESTED)
// WARNING: slow
struct Int {
	ll x;
	Int (ll n=0) { x = n % MOD; if (x < 0) x += MOD; }
	operator ll&() { return x; }
	Int operator + (const Int& n) const { return Int(x + n.x); }
	Int operator - (const Int& n) const { return Int(x - n.x); }
	Int operator * (const Int& n) const { return Int(x * n.x); }
	void operator += (const Int& n) { x = (x + n.x) % MOD; }
	void operator -= (const Int& n) { x = (x + MOD - n.x) % MOD; }
	void operator *= (const Int& n) { x = (x * n.x) % MOD; }
};
//*/

// Stores a set of disconnected intervals, amortized O(log n) / operation
// interval is inclusive / exclusive [a, b), find returns interval or {INF,INF}
struct interval_set { set<pii> s;
  void insert(int a, int b) { if (s.empty()) { s.insert({a, b}); return; }
    //! extend right (intervals starting > a)
    auto it1 = s.upper_bound({a, INF}); while (it1 != s.end()) {
      if ((*it1).first <= b) { auto it1nxt = it1; ++it1nxt;
        b = max(b, (*it1).second); s.erase(it1); it1 = it1nxt; } else break; }
    //! extend left (intervals starting <= a)
    it1 = s.upper_bound({a, INF}); if (it1 != s.begin()) { --it1; while (1) {
      if (a <= (*it1).second) { auto it1nxt = it1; --it1nxt;
        bool isBegin = (it1 == s.begin());
        a = min(a, (*it1).first); b = max(b, (*it1).second);
        s.erase(it1); it1 = it1nxt; if (isBegin) break; } else break; } }
    s.insert({a, b}); }
  pii find(int x) { if (s.empty()) return {INF, INF};
    auto it1 = s.upper_bound({x, INF});
    if (it1 == s.begin()) return {INF, INF}; --it1;
    if ((*it1).second <= x) return {INF, INF}; return *it1; } 
};

const int N = 1<<18;
interval_set iset[N];

// inclusive
struct SegTree {
	Int t[2*N], add[2*N], mul[2*N];
	SegTree() {
		memset(t, 0, sizeof t);
		memset(add, 0, sizeof add);
		fill(mul, mul+2*N, Int(1));
	}

	void push(int i, int len) {
		// first multiply
		t[2*i] *= mul[i];
		mul[2*i] *= mul[i];
		add[2*i] *= mul[i];
		t[2*i+1] *= mul[i];
		mul[2*i+1] *= mul[i];
		add[2*i+1] *= mul[i];
		mul[i] = Int(1);

		// second add
		t[2*i] += Int(len/2)*add[i];
		add[2*i] += add[i];
		t[2*i+1] += Int(len/2)*add[i];
		add[2*i+1] += add[i];
		add[i] = Int(0);
	}

	void pull(int i) {
		t[i] = t[2*i] + t[2*i+1];
	}

	void increment(int l, int r, int i=1, int s=0, int e=N-1) {
		if (r < s || l > e) return;
		if (l <= s && e <= r) {
			t[i] += Int(e-s+1);
			add[i] += Int(1);
			return;
		}
		push(i,e-s+1);

		int mid = (s+e)/2;
		increment(l, r, 2*i, s, mid);
		increment(l, r, 2*i+1, mid+1, e);
		pull(i);
	}

	void duplicate(int l, int r, int i=1, int s=0, int e=N-1) {
		if (r < s || l > e) return;
		if (l <= s && e <= r) {
			t[i] *= Int(2);
			add[i] *= Int(2);
			mul[i] *= Int(2);
			return;
		}
		push(i,e-s+1);

		int mid = (s+e)/2;
		duplicate(l, r, 2*i, s, mid);
		duplicate(l, r, 2*i+1, mid+1, e);
		pull(i);
	}

	Int query(int l, int r, int i=1, int s=0, int e=N-1) {
		if (r < s || l > e) return 0;
		if (l <= s && e <= r) {
			return t[i];
		}
		push(i,e-s+1);

		int mid = (s+e)/2;
		return query(l, r, 2*i, s, mid) + query(l, r, 2*i+1, mid+1, e);
	}
};
SegTree segtree;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, q;
	cin >> n >> q;

	int t, a, b, c;
	for (int i=0; i<q; i++) {
		cin >> t;

		if (t == 2) {
			cin >> a >> b;
			cout << segtree.query(a,b) << nl;
		}

		else {
			cin >> a >> b >> c;
			pii start = iset[c].find(a);
			pii last = iset[c].find(b);

			if (start.first != INF && start == last) {
				segtree.duplicate(a,b);
			}
			else {
				vector<pii> segs; // [l,r)
				if (start.first != INF) segs.push_back(pii(a, start.second));
				auto it = iset[c].s.upper_bound(pii(a, INF));
				while (it != iset[c].s.end() && it->second <= b) {
					segs.push_back(*it);
					++it;
				}
				if (last.first != INF) segs.push_back(pii(last.first, b+1));

				int cur = a;
				for (const pii& it : segs) {
					segtree.increment(cur, it.first-1);
					segtree.duplicate(it.first, it.second-1);
					cur = it.second;
				}
				segtree.increment(cur, b);

				iset[c].insert(a, b+1);
			}
		}
	}

	return 0;
}
#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;

const int MAXN = 100055;
const int MAXQ = 100055;

struct NOD {
	NOD() : l(NULL), r(NULL), lz(0), cnt(0) {}
	NOD *l, *r;
	ll lz;
	int cnt;

	void bomb() {
		if(l) {
			l -> bomb();
			delete l;
		}
		if(r) {
			r -> bomb();
			delete r;
		}
	}
	void prop() {
		if(!lz) return;
		if(l) l -> lz += lz;
		if(r) r -> lz += lz;
		lz = 0;
	}
	void push(int s, int e, int x, ll dt) {
		cnt++;
		if(s == e) {
			lz = dt;
			return;
		}
		prop();
		int m = (s+e) >> 1;
		if(x <= m) {
			if(!l) l = new NOD();
			l -> push(s, m, x, dt);
		} else {
			if(!r) r = new NOD();
			r -> push(m+1, e, x, dt);
		}
	}
	void pop(int s, int e, int x) {
		cnt--;
		if(s == e) return;
		prop();
		int m = (s+e) >> 1;
		if(x <= m) {
			l -> pop(s, m, x);
			if(!(l -> cnt)) {
				delete l;
				l = NULL;
			}
		} else {
			r -> pop(m+1, e, x);
			if(!(r -> cnt)) {
				delete r;
				r = NULL;
			}
		}
	}
	ll get(int s, int e, int x) {
		if(s == e) return lz;
		prop();
		int m = (s+e) >> 1;
		if(x <= m) return l -> get(s, m, x);
		else return r -> get(m+1, e, x);
	}
	void upd(int s, int e, int p, int q, ll dt) {
		if(p <= s && e <= q) {
			lz += dt;
			return;
		}
		if(s == e) return;
		prop();
		if(q < p || e < p || q < s) return;
		int m = (s+e) >> 1;
		if(l) l -> upd(s, m, p, q, dt);
		if(r) r -> upd(m+1, e, p, q, dt);
	}
};

struct SEG {
	SEG() { rt = new NOD(); }
	NOD *rt;
	set<int> XV;
	
	void bomb() { XV.clear(); rt->bomb(); rt = NULL; }
	int size() { return rt->cnt; }
	void getXV(vector<int> &V) {
		for(int v : XV) V.eb(v);
	}
	ll get(int N, int x) { return rt->get(1, N, x); }
	void push(int N, int x, ll y) {
		XV.insert(x);
		rt->push(1, N, x, y);
	}
	void upd(int N, int s, int e, ll x) { rt->upd(1, N, s, e, x); }
	void pop(int N, int x) {
		XV.erase(x);
		rt->pop(1, N, x);
	}
	ll getFront(int N, int x) {
		auto it = XV.lower_bound(x);
		if(XV.begin() == it) return 0;
		it--;
		return get(N, *it);
	}
	ll getMax(int N) {
		return get(N, *prev(XV.end()));
	}
};

vector<int> G[MAXN];
ll dp[MAXN];
int dep[MAXN];
int A[MAXN], QI[MAXN];
int B[MAXQ], C[MAXQ], D[MAXQ], O[MAXQ];

int N, Q, K;

void dfs(int i, SEG &seg) {
	for(int v : G[i]) {
		SEG cseg;
		dfs(v, cseg);
		if(sz(seg) < sz(cseg)) swap(seg, cseg);
		vector<int> XV; cseg.getXV(XV);
		int n = sz(XV);
		for(int vi = n, x; vi--;) {
			x = XV[vi];
			ll y = cseg.get(N, x) + seg.getFront(N, x);
			seg.push(N, x, y);
		}
		for(int i = 1; i < n; i++)
			seg.upd(N, XV[i-1]+1, XV[i]-1, cseg.get(N, XV[i-1]));
		if(n) seg.upd(N, XV.back()+1, N, cseg.get(N, XV.back()));
		cseg.bomb();
	}
	if(QI[i]) {
		int day = C[QI[i]];
		ll cost = D[QI[i]] + seg.getFront(N, day);
		seg.push(N, day, cost);
		for(;;) {
			auto it = seg.XV.upper_bound(day);
			if(seg.XV.end() == it) break;
			ll y = seg.get(N, *it);
			if(cost < y) break;
			seg.pop(N, *it);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q >> K;
	for(int i = 2; i <= N; i++) {
		cin >> A[i];
		G[A[i]].eb(i);
	}
	for(int i = 1; i <= Q; i++) {
		cin >> B[i] >> C[i] >> D[i];
		QI[B[i]] = i;
	}

	dep[1] = 1;
	for(int i = 2; i <= N; i++) dep[i] = dep[A[i]] + 1;
	iota(O, O+Q+1, 0); sort(O+1, O+Q+1, [&](int a, int b) {
		if(C[a] != C[b]) return C[a] < C[b];
		return dep[B[a]] > dep[B[b]];
	});
	for(int oi = 1; oi <= Q; oi++) C[O[oi]] = oi;

	SEG seg;
	dfs(1, seg);

	cout << seg.getMax(N) << endl;
	return 0;
}
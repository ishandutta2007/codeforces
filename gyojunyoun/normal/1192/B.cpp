#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

struct SEG {
	ll *dp, *ds;
	int n, _m;

	void calsize(int i, int s, int e) {
		if(_m < i) _m = i;
		if(s == e) return;
		int m = (s+e) >> 1;
		calsize(i<<1, s, m);
		calsize(i<<1|1, m+1, e);
	}
	void init(int _n) {
		n = _n; _m = 0;
		calsize(1, 0, n-1);
		dp = new ll[_m+1]();
		ds = new ll[_m+1]();
	}
	void upd(int i, int s, int e, int p, int q, ll r) {
		if(q < p || e < p || q < s) return;
		if(p <= s && e <= q) {
			ds[i] += r;
			dp[i] += r;
			return;
		}
		int m = (s+e) >> 1;
		upd(i<<1, s, m, p, q, r);
		upd(i<<1|1, m+1, e, p, q, r);
		dp[i] = max(dp[i<<1], dp[i<<1|1]) + ds[i];
	}
	void upd(int s, int e, ll x) { upd(1, 0, n-1, s, e, x); }
	ll get() { return dp[1]; }
} *seg[MAXN];

struct NOD {
	multiset<ll> P;
	void push(ll x) { P.insert(x); }
	void pop(ll x) { P.erase(P.find(x)); }
	ll get() {
		if(P.empty()) return -INFLL;
		if(1 == sz(P)) return *P.begin();
		return *prev(P.end()) + *prev(prev(P.end()));
	}
	ll getone() { return P.empty() ? -INFLL : *prev(P.end()); }
} nod[MAXN];

int CI[MAXN][17], CJ[MAXN][17], Cdfo[MAXN][17], Ccnt[MAXN][17];
int ECI[MAXN][17], ECJ[MAXN][17];
int *Csubcnt[MAXN];
int CH[MAXN], Cprt[MAXN], Cdg[MAXN];

vector<int> G[MAXN];
int cnt[MAXN];
bitset<MAXN> chk;

int A[MAXN], B[MAXN];
ll C[MAXN];

ll MXX, Ans;
int N, Q;

void upd(int e, ll del) {
	int lv = 16;
	for(; !ECI[e][lv]; lv--);
	for(int rt = ECI[e][lv], j, a = A[e], b = B[e]; rt; lv--, rt = Cprt[rt]) {
		if(a == rt || b == rt) {
			if(b == rt) swap(a, b);
		} else if(Cdfo[a][lv] > Cdfo[b][lv]) swap(a, b);
		j = ECJ[e][lv];
		nod[0].pop(nod[rt].get());
		nod[rt].pop(seg[rt][j].get());
		seg[rt][j].upd(Cdfo[b][lv], Cdfo[b][lv]+Ccnt[b][lv]-1, del);
		nod[rt].push(seg[rt][j].get());
		nod[0].push(nod[rt].get());
	}
}

void cent(int &rt) {
	const int N = cnt[rt];
	for(int hi, hc;;) {
		hi = hc = -1;
		for(int e : G[rt]) {
			int v = A[e]^B[e]^rt;
			if(N <= cnt[v] || cnt[v] <= hc) continue;
			hi = v; hc = cnt[v];
		}
		if(hc*2 <= N) break;
		cnt[rt] = N-hc;
		cnt[hi] = N;
		rt = hi;
	}
}

void centdfs(int i, int lv, int &c) {
	Cdfo[i][lv] = c++;
	Ccnt[i][lv] = 1;
	for(int e : G[i]) {
		int v = A[e]^B[e]^i;
		if(cnt[i] <= cnt[v] || chk[v]) continue;
		ECI[e][lv] = CI[v][lv] = CI[i][lv];
		ECJ[e][lv] = CJ[v][lv] = CJ[i][lv];
		centdfs(v, lv, c);
		Ccnt[i][lv] += Ccnt[v][lv];
	}
}

void makeCT(int i, int p, int lv) {
	cent(i);
	chk[i] = true;
	CH[i] = lv; CI[i][lv] = i;
	Cprt[i] = p;
	vector<pii> V;
	for(int e : G[i]) {
		int v = A[e]^B[e]^i;
		if(cnt[i] <= cnt[v] || chk[v]) continue;
		V.eb(v, e);
	}
	Cdg[i] = sz(V);
	Csubcnt[i] = new int[sz(V)]();
	seg[i] = new SEG[Cdg[i]]();
	for(int j = sz(V), v, e; j--;) {
		tie(v, e) = V[j];
		int c = 0;
		ECI[e][lv] = CI[v][lv] = i;
		ECJ[e][lv] = CJ[v][lv] = j;
		centdfs(v, lv, c);
		Csubcnt[i][j] = c;
		seg[i][j].init(c);
		nod[i].push(0);
	}
	nod[0].push(0);
	for(auto &e : V) makeCT(e.first, i, lv+1);
}

void predfs(int i) {
	cnt[i] = 1;
	for(int e : G[i]) {
		int v = A[e]^B[e]^i;
		if(cnt[v]) continue;
		predfs(v);
		cnt[i] += cnt[v];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q >> MXX;
	for(int i = 1; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].eb(i);
		G[B[i]].eb(i);
	}
	predfs(1);
	makeCT(1, 0, 0);

	for(int i = 1; i < N; i++) upd(i, C[i]);

	for(ll a, b, del; Q--;) {
		cin >> a >> b;
		a = (a + Ans) % (N-1) + 1;
		b = (b + Ans) % MXX;
		del = -C[a];
		C[a] = b;
		del += b;
		upd(a, del);
		Ans = nod[0].getone();
		cout << Ans << '\n';
	}
	return 0;
}
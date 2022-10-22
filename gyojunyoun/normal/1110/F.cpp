#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define cb(x) (x)=(!(x))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define INFST (0x7f7f7f7f)
#define INFLLST (0x7f7f7f7f7f7f7f7fll)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
typedef complex<ld> base;
const ld EPS = (ld)1e-7;
const ld PI = acos(0) * 2;
bool isZero(const ld& x) { return abs(x) <= EPS; }
int sign(const ld& x) { return isZero(x) ? 0 : (0 < x ? 1 : -1); }
ll gcd(ll a, ll b) { for(;b;a%=b,swap(a,b)){} return abs(a); }
pll operator + (const pll& a, const pll& b) { return pll(a.first+b.first, a.second+b.second); }
pll operator - (const pll& a, const pll& b) { return pll(a.first-b.first, a.second-b.second); }
pll operator * (const pll& a, const ll& b) { return pll(a.first*b, a.second*b); }
ll operator * (const pll& a, const pll& b) { return a.first*b.second - b.first*a.second; }
ll ccw(const pll& a, const pll& b, const pll& c) { return a*b + b*c + c*a; }
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }
static unsigned char str[27500055], *p=str;

const int MAXN = 500055;

ll _ll[40004455], *_llp = _ll;
inline ll* newll(const unsigned int SZ) {
	_llp += SZ;
	return _llp - SZ;
}

struct SEG {
	ll *d;
	int n, k;
	void init(int _n) {
		n = _n;
		for(k = 1; k < n; k <<= 1);
		d = newll(k*2);
	}
	void upd(int x, ll r) {
		x += k; d[x] = r;
		for(x >>= 1; x; x >>= 1)
			d[x] = min(d[x<<1], d[x<<1|1]);
	}
	ll get(int s, int e) {
		ll r = INFLL;
		for(s += k, e += k; s <= e; s >>= 1, e >>= 1) {
			if(s & 1) { upmin(r, d[s]); s++; }
			if(~e&1) { upmin(r, d[e]); e--; }
		}
		return r;
	}
} seg[MAXN];

vector<int> LV[MAXN];
int cprt[MAXN];

vector<int> G[MAXN];
int prt[19][MAXN], dep[MAXN], cnt[MAXN];
ll dl[MAXN];

int A[MAXN], B[MAXN], C[MAXN];

int N, Q, Rt;

int lca(int a, int b) {
	if(dep[a] > dep[b]) swap(a, b);
	const int dt = dep[b] - dep[a];
	for(int i = 19; i--;) if(dt & (1<<i))
		b = prt[i][b];
	if(a == b) return a;
	for(int i = 19; i--;) if(prt[i][a] != prt[i][b]) {
		a = prt[i][a];
		b = prt[i][b];
	}
	return prt[0][a];
}

ll getDist(int a, int b) {
	if(a == b) return 0;
	int c = lca(a, b);
	return dl[a]-dl[c] + dl[b]-dl[c];
}

void dfs(int i) {
	cnt[i] = 1;
	for(int e : G[i]) {
		int v = A[e] + B[e] - i;
		if(dep[v]) continue;
		dep[v] = dep[i] + 1;
		prt[0][v] = i;
		dl[v] = dl[i] + C[e];
		dfs(v);
		cnt[i] += cnt[v];
	}
}

void dfs(vector<int> &V, int i) {
	if(1 == sz(G[i])) {
		V.eb(i);
		return;
	}
	for(int e : G[i]) {
		int v = A[e] + B[e] - i;
		if(cnt[i] <= cnt[v]) continue;
		dfs(V, v);
	}
}

int centdfs(int rt) {
	const int N = cnt[rt];
	for(int hi, hc;;) {
		hi = hc = -1;
		for(int e : G[rt]) {
			int v = A[e] + B[e] - rt;
			if(N <= cnt[v]) continue;
			if(cnt[v] <= hc) continue;
			hc = cnt[v]; hi = v;
		}
		if(hc*2 <= N) break;
		cnt[rt] = N-hc;
		cnt[hi] = N;
		rt = hi;
	}

	dfs(LV[rt], rt);
	sorv(LV[rt]);
	seg[rt].init(sz(LV[rt]));
	for(int i = 0, n = sz(LV[rt]); i < n; i++)
		seg[rt].upd(i, getDist(rt, LV[rt][i]));
	
	for(int e : G[rt]) {
		int v = A[e] + B[e] - rt;
		if(N <= cnt[v]) continue;
		int t = centdfs(v);
		cprt[t] = rt;
	}
	return rt;
}

ll getAns(int v, int l, int r) {
	ll ret = INFLL;
	for(int n, s, e, rt = v; rt;) {
		n = sz(LV[rt]);
		s = int(lower_bound(allv(LV[rt]), l) - LV[rt].begin());
		e = int(upper_bound(allv(LV[rt]), r) - LV[rt].begin()) - 1;
		upmin(ret, seg[rt].get(s, e) + getDist(v, rt));
		rt = cprt[rt];
	}
	return ret;
}

int main() {
	fill(_ll, _ll+40004455, INFLL);
	fread(str, 1, 27500055, stdin);

	rf(N) rf(Q)
	for(int i = 2; i <= N; i++) {
		A[i] = i; rf(B[i]) rf(C[i])
		G[A[i]].eb(i);
		G[B[i]].eb(i);
	}
	dep[1] = 1; dfs(1);
	for(int j = 1; j < 19; j++) for(int i = 1; i <= N; i++)
		prt[j][i] = prt[j-1][prt[j-1][i]];
	Rt = centdfs(1);

	for(int a, b, c; Q--;) {
		rf(a) rf(b) rf(c)
		printf("%lld\n", getAns(a, b, c));
	}
	return 0;
}
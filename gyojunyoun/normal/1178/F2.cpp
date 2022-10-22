#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p++=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
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

const int MOD = 998244353;

const int MAXN = 515;
const int MAXK = 1000055;

struct BIT {
	int d[MAXK];

	void init() { memset(d, 0, MAXK<<2); }
	void upd(int x, int r) {
		for(x += 5; x < MAXK; x += rb(x))
			d[x] += r;
	}
	int get(int x) {
		int r = 0; for(x += 5; x; x -= rb(x))
			r += d[x];
		return r;
	}
	int get(int s, int e) { return s > e ? 0 : get(e)-get(s-1); }
} bit;

int E[MAXN*2][MAXN*2];
ll D[MAXN*2][MAXN*2];
bitset<MAXN*2> chk[MAXN*2];
bitset<MAXN*2> isLE, isRE;

bitset<MAXN*2> CMP[MAXN];

vector<int> CX[MAXK];

vector<int> XV;
int BL[MAXK], BR[MAXK];
int L[MAXK], R[MAXK];
int A[MAXK];

int N, K;

ll f(int s, int e) {
	if(s > e) return 1;
	if(s < 0) s = 1;
	if(sz(XV) < e) e = sz(XV);
	if(chk[s][e]) return D[s][e];

	int mni = E[s][e];
	if(N < mni) {
		chk[s][e] = true;
		return D[s][e] = 0;
	}
	int ms = L[mni], me = R[mni];
	ll dl = 0, dr = 0;
	for(int i = max(s, BL[mni]); i <= ms; i++) if(isLE[i] && !CMP[mni][i])
		dl = (dl + f(s, i-1) * f(i, ms-1)) % MOD;
	for(int i = me; i <= min(e, BR[mni]); i++) if(isRE[i] && !CMP[mni][i])
		dr = (dr + f(me+1, i) * f(i+1, e)) % MOD;
	ll ret = dl * dr % MOD * f(ms+1, me-1) % MOD;
	chk[s][e] = true;
	D[s][e] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for(int i = 1; i <= N; i++) {
		L[i] = K;
		R[i] = 1;
	}
	for(int i = 1; i <= K; i++) {
		cin >> A[i];
		upmin(L[A[i]], i);
		upmax(R[A[i]], i);
		CX[A[i]].eb(i);
	}

	for(int i = 1; i < N; i++) for(int j = i+1; j <= N; j++) {
		int as = L[i], ae = R[i];
		int bs = L[j], be = R[j];
		if(bs <= as && ae <= be) {
			puts("0");
			return 0;
		}
		if(as > bs) {
			swap(as, bs);
			swap(ae, be);
		}
		if(as <= bs && bs <= ae && ae <= be) {
			puts("0");
			return 0;
		}
	}
	for(int i = 1; i <= N; i++) {
		if(bit.get(L[i], R[i])) {
			puts("0");
			return 0;
		}
		for(int v : CX[i]) bit.upd(v, 1);
	}

	for(int i = 1; i <= N; i++) {
		XV.eb(L[i]);
		XV.eb(R[i]);
	}
	sorv(XV); univ(XV);
	{
		set<int> CH;
		CH.insert(0); CH.insert(K+1);
		for(int i = 1; i <= N; i++) {
			int xs = *prev(CH.lower_bound(L[i]));
			int xe = *CH.upper_bound(R[i]);
			BL[i] = int(lower_bound(allv(XV), xs) - XV.begin()) + 1;
			BR[i] = int(upper_bound(allv(XV), xe) - XV.begin());
			for(int v : CX[i]) CH.insert(v);
		}
	}
	for(int i = 1; i <= N; i++) {
		L[i] = int(lower_bound(allv(XV), L[i]) - XV.begin()) + 1;
		R[i] = int(lower_bound(allv(XV), R[i]) - XV.begin()) + 1;
		isLE[L[i]] = true;
		isRE[R[i]] = true;
	}
	for(int i = N; i; i--) {
		CMP[i] = CMP[i+1];
		int s = L[i]+1, e = R[i]-1;
		for(int j = s; j <= e; j++)
			CMP[i][j] = true;
	}

	fill(E[0], E[MAXN*2-1] + MAXN*2, INF);
	for(int i = 1; i <= N; i++) E[L[i]][R[i]] = i;
	int L = sz(XV);
	for(int l = 2; l <= L; l++) {
		for(int s = 1, e = l; e <= L; s++, e++) {
			upmin(E[s][e], min(E[s][e-1], E[s+1][e]));
		}
	}

	cout << f(1, sz(XV)) << endl;
	return 0;
}
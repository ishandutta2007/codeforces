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
#define fi first
#define se second
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
void fg(vector<int> G[], int a, int b) { G[a].eb(b); G[b].eb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].eb(b, c); G[b].eb(a, c); }

const int MOD = 998244353;
const int MAXN = 100055;

inline ll pw(ll n, ll k) {
	ll r = 1; for(n %= MOD; k; k >>= 1) {
		if(k&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}
inline ll inv(ll n) { return pw(n, MOD-2); }

struct EVT {
	EVT(int i, ll a, ll b, bool l, bool r)
		: i(i), a(a), b(b), l(l), r(r) {}
	int i; ll a, b;
	bool l, r;

	bool operator < (const EVT &t) const {
		// a/b < ta/tb
		return a*t.b < b*t.a;
	}
};

vector<EVT> EV;

ll dp[MAXN*4][2][2];

ll A[MAXN], B[MAXN], C[MAXN], D[MAXN];
bool chk[MAXN][2][2];

ll Ans;
int N;

void merge(int i, int s, int e) {
	int m = s+e >> 1;
	memset(dp[i][0], 0, 2*2*8);
	for(int a = 2; a--;) for(int b = 2; b--;) if(!chk[m][a][b])
		for(int c = 2; c--;) for(int d = 2; d--;)
			dp[i][c][d] += dp[i<<1][c][a] * dp[i<<1|1][b][d];
	for(int a = 2; a--;) for(int b = 2; b--;) dp[i][a][b] %= MOD;
}

void init(int i, int s, int e) {
	if(s == e) {
		dp[i][0][0] = C[s];
		dp[i][1][1] = D[s];
		return;
	}
	int m = s+e >> 1;
	init(i<<1, s, m);
	init(i<<1|1, m+1, e);
	merge(i, s, e);
}

void upd(int i, int s, int e, int p) {
	if(s == e) return;
	int m = s+e >> 1;
	if(p < m) upd(i<<1, s, m, p);
	if(m < p) upd(i<<1|1, m+1, e, p);
	merge(i, s, e);
}

ll get() {
	ll r = 0;
	for(int a = 2; a--;) for(int b = 2; b--;)
		r += dp[1][a][b];
	return r % MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i] >> C[i];
		C[i] = C[i] * inv(100) % MOD;
		D[i] = (MOD + 1 - C[i]) % MOD;
	}
	for(int i = 1; i < N; i++) {
		EV.eb(i, A[i+1]-A[i], B[i]+B[i+1], false, true);
		if(B[i] > B[i+1]) EV.eb(i, A[i+1]-A[i], B[i]-B[i+1], false, false);
		if(B[i] < B[i+1]) EV.eb(i, A[i+1]-A[i], B[i+1]-B[i], true, true);
	}
	if(EV.empty()) {
		puts("0");
		exit(0);
	}
	sorv(EV);

	init(1, 1, N);
	for(auto &ev : EV) {
		int i = ev.i, l = ev.l, r = ev.r;
		ll x = ev.a * inv(ev.b) % MOD;

		ll p = get();
		chk[i][l][r] = true;
		upd(1, 1, N, i);
		p = ((p - get()) % MOD + MOD) % MOD;

		Ans = (Ans + x*p) % MOD;
	}

	cout << Ans << endl;
	return 0;
}
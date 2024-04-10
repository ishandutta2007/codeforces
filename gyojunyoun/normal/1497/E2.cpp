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
void fg(vector<int> G[], int a, int b) { G[a].eb(b); G[b].eb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].eb(b, c); G[b].eb(a, c); }
int rd(int s, int e) { return rand()%(e-s+1) + s; }


namespace LIB_MATH {
	// a*b % MOD
	ll mul(ll a, ll b, const ll &mod) {
		ll ret = 0;
		for(a %= mod, b %= mod; a; a >>= 1) {
			if(a&1) ret = (ret + b) % mod;
			b = (b<<1) % mod;
		}
		return ret;
	}
	// a^b % MOD
	ll mypow(ll a, ll b, const ll& mod) {
		ll ret = 1; for(a %= mod; b; b >>= 1) {
			if(b&1) ret = mul(ret, a, mod);
			a = mul(a, a, mod);
		}
		return ret;
	}
}

namespace LIB_MRT { // Miller-Rabin
	// Need LIB_MATH
	bool mrtest(ll x, ll a) {
		if(!(x%a)) return false;
		for(ll d = x-1, t;; d >>= 1) {
			t = LIB_MATH :: mypow(a, d, x);
			if(d&1) return ((1 != t) && (x-1 != t));
			if(x-1 == t) return false;
		}
		return false;
	}
	const int V[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

	bool run(ll x, const bool iscut = true) { // Check that x is a prime
		if(2 == x) return true;
		if(x < 2 || !(x&1)) return false;
		if(iscut && x < 10000) {
			for(int i = 3; i*i <= x; i += 2)
				if(!(x%i)) return false;
			return true;
		}
		for(int v : V) {
			if(x == v) return true;
			if(40 < x && mrtest(x, v)) return false;
		}
		return 40 < x;
	}
}

namespace LIB_FTZ { // Factorization
	// Need LIB_MATH, LIB_MRT
	ll f(ll x, ll n, ll c) {
		return (LIB_MATH :: mul(x, x, n) + c) % n;
	}
	void g(vector<ll> &ret, ll x) {
		if(1 == x) return;
		if(LIB_MRT :: run(x)) {
			ret.pb(x); return;
		}
		for(ll a, b, c, t;;) {
			a = b = rd(2, x-1);
			c = rd(1, 20);
			do {
				a = f(a, x, c);
				b = f(f(b, x, c), x, c);
			} while(1 == (t = gcd(abs(a-b), x)));
			if(a == b) continue;
			g(ret, t); g(ret, x/t);
			return;
		}
	}

	void run(vector<ll> &ret, ll x) {
		clv(ret); if(x < 2) return;
		for(; !(x&1); x >>= 1) ret.pb(2);
		g(ret, x);
		sorv(ret);
	}
}


const int MAXX = 10055;
const int MAXN = 200055;

bitset<MAXX> isnp;

void ftz(vector<int> &V, int x) {
	if(x < 2) return;
	while(!(x&1)) {
		x >>= 1;
		V.eb(2);
	}
	for(int p = 3; p*p <= x; p += 2) if(!isnp[p]) {
		while(0 == x % p) {
			x /= p;
			V.eb(p);
		}
	}
	if(1 < x)
		V.eb(x);
}

int DP[MAXN][22];
int NXT[22];

int A[MAXN], B[MAXN];

int N, K;

void run() {
	cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> A[i];

	for(int i = 1; i <= N; i++) {
		vector<int> V; ftz(V, A[i]);

		int ret = 1;
	
		int n = sz(V);
		for(int s = 0, e; s < n; s = e) {
			for(e = s+1; e < n && V[e] == V[s]; e++);
			if((e-s) & 1) ret *= V[s];
		}

		A[i] = ret;
	}

	{
		map<int, int> MP;

		for(int i = N; i; i--) {
			int t = MP[A[i]];
			if(!t) B[i] = N+1;
			else B[i] = t;
			MP[A[i]] = i;
		}
	}

	set<int> PQ;
	for(int i = 1; i <= N; i++)
		if(B[i]) PQ.emplace(B[i]);
	PQ.emplace(N+1);

	fill(DP[0], DP[N+2], INF);

	DP[0][0] = 0;

	for(int i = 0; i < N; i++) {
		fill(NXT, NXT+22, 0);

		auto it = PQ.begin();
		NXT[0] = *it - 1;

		for(int j = 1; j <= K; j++) {
			if(PQ.end() != it) it++;
			if(PQ.end() == it)
				NXT[j] = N;
			else NXT[j] = *it - 1;
		}

		for(int j = 0; j <= K; j++) if(DP[i][j] < INF) {
			for(int k = 0; j+k <= K; k++) {
				upmin(DP[NXT[k]][j+k], DP[i][j] + 1);
			}
		}

		if(B[i+1] && B[i+1] < N+1) {
			auto it = PQ.find(B[i+1]);
			if(PQ.end() != it)
				PQ.erase(it);
		}
	}

	cout << *min_element(DP[N], DP[N]+K+1) << '\n';
}

int main() {
	isnp[0] = isnp[1] = true;
	for(int i = 4; i < MAXX; i += 2) isnp[i] = true;
	for(int i = 3; i*i < MAXX; i += 2) if(!isnp[i])
		for(int j = i*i; j < MAXX; j += i+i) isnp[j] = true;

	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	for(; T--;) run();

	return 0;
}
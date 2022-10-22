#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
#define fi first
#define se second
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

const int MAXN = 50005;
const int MAXM = 100005;


const int MX = 65536;


struct SEGY {
	SEGY() : l(0), r(0), mn(INF) {}
	int l, r, mn;
} segy[MAXM * 18 * 18 + 55];
int segycnt;


int N, M;


void pushY(int i, int s, int e, int x, int dt) {
	int m;
	while(true) {
		if(dt < segy[i].mn) segy[i].mn = dt;
		if(s == e) return;
		m = s+e >> 1;
		if(x <= m) {
			if(!segy[i].l) segy[i].l = ++segycnt;
			i = segy[i].l; e = m;
		} else {
			if(!segy[i].r) segy[i].r = ++segycnt;
			i = segy[i].r; s = m+1;
		}
	}
}
void pushY(int i, int x, int dt) {
	pushY(i, 1, N, x, dt);
}


int getY(int i, int s, int e, int p, int q) {
	if(!i || e < p || q < s) return INF;
	if(p <= s && e <= q) return segy[i].mn;
	int m = s+e >> 1;
	return min(getY(segy[i].l, s, m, p, q), getY(segy[i].r, m+1, e, p, q));
}
int getY(int i, int s, int e) {
	return getY(i, 1, N, s, e);
}


struct SEGX {
	SEGX() { init(); }

	int dp[MX*2];

	void init() {
		for(int i = 0; i < MX*2; i++)
			dp[i] = ++segycnt;
	}

	void push(int x, int y, int dt) {
		int i = x + MX;
		while(i) {
			::pushY(dp[i], y, dt);
			i >>= 1;
		}
	}

	int get(int p, int q, int x) {
		int ret = INF;
		int s = MX + p, e = MX + q-x+1;
		while(s <= e) {
			if(s&1) upmin(ret, ::getY(dp[s++], p, q));
			if(~e&1) upmin(ret, ::getY(dp[e--], p, q));
			s >>= 1; e >>= 1;
		}
		return ret;
	}
} segx;


vector<int> G[MAXN];

int A[MAXM], B[MAXM];

int Ans[MAXN];


void solve(int x, int s, int e) {
	if(e-s+1 < x) return;

	int i = segx.get(s, e, x);
	if(M < i) return;

	Ans[x] += B[i]-A[i]+1;

	solve(x, s, A[i]-1);
	solve(x, B[i]+1, e);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for(int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[B[i]-A[i]+1].eb(i);
	}


	for(int x = N; x; x--) {
		for(int i : G[x]) segx.push(A[i], B[i], i);

		solve(x, 1, N);
	}


	for(int i = 1; i <= N; i++) cout << Ans[i] << '\n';
	return 0;
}
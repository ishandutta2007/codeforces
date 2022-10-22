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

const int MOD = 998244353;
const int MAXN = 100055;
const int SQRT = 320;

vector<int> CA, CB;
int C[2][MAXN];

int A[MAXN];

int N;

pii f(int x, int y) {
	if(x <= y) return {0, x};
	int t = (x-1)/y;
	return {t, x/(t+1)};
}

void run() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];

	// A[i+1]

	CA.clear(); CB.clear();

	int Ans = 0;
	for(int q = 1; q <= SQRT; q++) {
		C[0][q] = f(A[0], q).fi;
		int t = A[1]/q;
		if(SQRT < t) C[0][t] = f(A[0], t).fi;
		CA.eb(q); CA.eb(t);
	}

	for(int i = 1; i < N; i++) {
		Ans += C[0][A[i]];
		if(MOD <= Ans) Ans -= MOD;
		if(i+1 == N) break;
		for(int q = 1; q <= SQRT; q++) {
			int a, b; tie(a, b) = f(A[i], q);
			C[1][q] = (ll(a) * (i+1) + C[0][b]) % MOD;
			int t = A[i+1]/q;
			if(SQRT < t) {
				tie(a, b) = f(A[i], t);
				C[1][t] = (ll(a) * (i+1) + C[0][b]) % MOD;
			}
			CB.eb(q); CB.eb(t);
		}
		for(int v : CA) C[0][v] = 0;
		for(int v : CB) C[0][v] = C[1][v];
		swap(CA, CB);
		CB.clear();
	}

	cout << Ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	while(T--) run();

	return 0;
}
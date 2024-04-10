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
static unsigned char str[55000055], *p=str;

int dp[805][4005];

int A[4005][4005], D[4005][4005];

int N, K;

void solve(int B[], int C[], int s, int e, int p, int q) {
	if(s > e) return;
	int m = s+e >> 1;
	int hi = -1, hc = INF;
	for(int i = p, t; i <= q && i < m; i++) {
		t = B[i] + D[i+1][m];
		if(hc <= t) continue;
		hi = i; hc = t;
	}
	C[m] = hc;
	solve(B, C, s, m-1, p, hi);
	solve(B, C, m+1, e, hi, q);
}

int main() {
	fread(str, 1, 55000055, stdin);

	rf(N) rf(K)
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) {
		rf(A[i][j])
		A[i][j] += A[i-1][j] - A[i-1][j-1] + A[i][j-1];
	}
	for(int i = 1; i < N; i++) for(int j = i+1; j <= N; j++)
		D[i][j] = (A[j][j] - A[i-1][j] + A[i-1][i-1] - A[j][i-1]) >> 1;
	fill(dp[0]+1, dp[0]+N+1, INF);
	for(int k = 1; k <= K; k++) {
		solve(dp[k-1], dp[k], k, N, k-1, N-1);
	}
	cout << dp[K][N] << endl;
	return 0;
}
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
ll lcm(ll a, ll b) { return a*b / gcd(a, b); }

const int MAXN = 500055;

vector<int> G[MAXN];

ll dp[MAXN][2];

int A[MAXN], B[MAXN], C[MAXN];

int T, N, K;

void f(int i, int p) {
	dp[i][0] = dp[i][1] = 0;
	vector<ll> V;
	int dg = 0, dgc = 0;
	for(int e : G[i]) {
		int v = A[e]^B[e]^i;
		if(v == p) continue;
		dg++;

		f(v, i);

		ll a = dp[v][1] + C[e], b = dp[v][0];
		if(a > b) {
			dp[i][1] += a;
			V.eb(-a+b);
			dgc++;
		} else dp[i][1] += b;
	}
	dp[i][0] = dp[i][1];
	sorv(V); revv(V);

	if(K < dgc) {
		for(int j = 0, c = min(sz(V), dgc-K); j < c; j++)
			dp[i][0] += V[j];
	}
	if(K <= dgc) {
		for(int j = 0, c = min(sz(V), dgc-K+1); j < c; j++)
			dp[i][1] += V[j];
	}
}

void run() {
	cin >> N >> K;
	for(int i = 1; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].eb(i);
		G[B[i]].eb(i);
	}
	f(1, -1);
	cout << dp[1][0] << '\n';
	for(int i = 1; i <= N; i++) G[i].clear();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(cin >> T; T--;) run();


	return 0;
}
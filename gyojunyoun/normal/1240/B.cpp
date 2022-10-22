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

const int MAXN = 300055;

struct BIT {
	int d[MAXN];

	void init(int x) {
		for(x += 5; x < MAXN; x += rb(x))
			d[x] = 0;
	}
	void upd(int x, int r) {
		for(x += 5; x < MAXN; x += rb(x))
			upmax(d[x], r);
	}
	int get(int x) {
		int r = 0; for(x += 5; x; x -= rb(x))
			upmax(r, d[x]);
		return r;
	}
} bit;

int dp[MAXN];
int B[MAXN], C[MAXN];
int A[MAXN];

int T, N, K, Ans;

void run() {
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	{
		vector<int> V;
		for(int i = 1; i <= N; i++) V.eb(A[i]);
		sorv(V); univ(V);
		for(int i = 1; i <= N; i++)
			A[i] = int(lower_bound(allv(V), A[i]) - V.begin()) + 1;
		K = sz(V);
	}
	fill(B, B+N+1, INF); fill(C, C+N+1, -1);
	for(int i = 1; i <= N; i++) {
		upmin(B[A[i]], i);
		upmax(C[A[i]], i);
	}
	Ans = 0;
	vector<int> XV;
	C[0] = 0;
	for(int x = 1; x <= K; x++) {
		dp[x] = 1;
		if(C[x-1] < B[x]) upmax(dp[x], dp[x-1] + 1);
		upmax(Ans, dp[x]);
	}
	cout << K-Ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(cin >> T; T--;) run();


	return 0;
}
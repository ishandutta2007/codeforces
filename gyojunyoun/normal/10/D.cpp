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
typedef pair<int, pii> piii;

struct BIT {
	piii d[505][505];

	void upd(int y, int x, int r) {
		piii t(r, {y, x});
		for(int i = y; i < 505; i += rb(i))
			for(int j = x; j < 505; j += rb(j))
				upmax(d[i][j], t);
	}
	piii get(int y, int x) {
		piii r(0, {0, 0});
		for(int i = y; i; i -= rb(i))
			for(int j = x; j; j -= rb(j))
				upmax(r, d[i][j]);
		return r;
	}
} bit;

vector<int> AI[1005], BI[1005];

pii rdp[505][505];
int dp[505][505];

int A[505], B[505];

int N, M;

int main() {
	cin >> N; for(int i = 1; i <= N; i++) cin >> A[i];
	cin >> M; for(int i = 1; i <= M; i++) cin >> B[i];

	{
		vector<int> V;
		for(int i = N; i; i--) V.eb(A[i]);
		for(int i = M; i; i--) V.eb(B[i]);
		sorv(V); univ(V);
		for(int i = N; i; i--) AI[lower_bound(allv(V), A[i]) - V.begin() + 1].eb(i);
		for(int i = M; i; i--) BI[lower_bound(allv(V), B[i]) - V.begin() + 1].eb(i);
	}

	for(int x = 1; x <= N+M; x++) {
		for(int i : AI[x]) for(int j : BI[x]) {
			auto ret = bit.get(i, j);
			dp[i][j] = ret.fi + 1;
			rdp[i][j] = ret.se;
			bit.upd(i, j, dp[i][j]);
		}
	}

	{
		int ret = 0, y = 0, x = 0;
		for(int i = N; i; i--) for(int j = M; j; j--)
			if(ret < dp[i][j]) { ret = dp[i][j]; y = i; x = j; }

		vector<int> V;
		for(; y && x;) {
			V.eb(A[y]);
			tie(y, x) = rdp[y][x];
		}
		revv(V);

		cout << ret << '\n';
		for(int v : V) cout << v << ' ';
		cout << '\n';
	}
	return 0;
}
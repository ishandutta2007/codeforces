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

inline void add(int &a, int b) { a += b; if(MOD <= a) a -= MOD; }

int D[5005][5005], DS[5005][5005];
int L[5005], E[5005];

vector<int> G[5005];

int N, K;

void dfs(int i, int p) {
	D[i][0] = 1;
	DS[i][0] = 1;

	for(int v : G[i]) if(v != p) {
		dfs(v, i);
		upmax(L[i], L[v] + 1);
		upmin(L[i], K);

		memset(E, 0, (L[i]+2) << 2);

		DS[i][0] = D[i][0];
		for(int j = 1; j <= L[i]; j++) {
			DS[i][j] = DS[i][j-1];
			add(DS[i][j], D[i][j]);
		}

		int sum = 0;
		for(int j = 0; j <= L[v]; j++)
			add(sum, D[v][j]);

		for(int j = 0; j <= L[i]; j++)
			E[j] = ll(D[i][j]) * sum % MOD;

		for(int d1 = 0; d1 <= L[i]; d1++) {
			// 0 <= d2 <= min(d1 - 1, K - d1 - 1)
			int d2 = min({d1 - 1, K - d1 - 1, L[v]});
			if(0 <= d2)
				E[d1] = (ll(D[i][d1]) * DS[v][d2] + E[d1]) % MOD;
		}

		for(int d2 = 0; d2 <= L[v] && d2 < K; d2++) {
			// 0 <= d1 <= min(d2, K - d2 - 1)
			int d1 = min({d2, K - d2 - 1, L[i]});
			if(0 <= d1)
				E[d2+1] = (ll(D[v][d2]) * DS[i][d1] + E[d2+1]) % MOD;
		}

		memcpy(D[i], E, (L[i]+1) << 2);
	}

	DS[i][0] = D[i][0];
	for(int j = 1; j <= L[i]; j++) {
		DS[i][j] = DS[i][j-1];
		add(DS[i][j], D[i][j]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for(int i = 1, a, b; i < N; i++) {
		cin >> a >> b;
		fg(G, a, b);
	}

	dfs(1, 0);

	int Ans = 0;
	for(int i = 0; i <= L[1]; i++)
		add(Ans, D[1][i]);
	
	cout << Ans << '\n';
	return 0;
}
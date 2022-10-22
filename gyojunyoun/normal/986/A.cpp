#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
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

const int MAXN = 100005;
const int MAXK = 105;

vector<int> G[MAXN];

int dp[MAXK][MAXN];

vector<int> KV[MAXK];

int A[MAXN];
int N, M, K, S;

int main() {
	for(int i = 0; i < MAXK; i++) fill(dp[i], dp[i]+MAXN, INF);
	scanf("%d%d%d%d", &N, &M, &K, &S);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		KV[A[i]].pb(i);
	}
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		fg(G, a, b);
	}

	for(int ci = 1; ci <= K; ci++) {
		queue<pii> PQ;
		for(int v : KV[ci]) {
			dp[ci][v] = 0;
			PQ.push(pii(v, 0));
		}

		for(int i, d; !PQ.empty(); PQ.pop()) {
			tie(i, d) = PQ.front(); d++;
			for(int v : G[i]) {
				int &ret = dp[ci][v];
				if(ret <= d) continue;
				ret = d;
				PQ.push(pii(v, d));
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		vector<int> V;
		for(int j = 1; j <= K; j++) V.pb(dp[j][i]);
		sorv(V);

		ll r = 0;
		for(int j = 0; j < S; j++) r += V[j];
		printf("%lld ", r);
	}
	puts("");
	return 0;
}
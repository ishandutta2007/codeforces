#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
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
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }

const int MAXN = 300055;

int dp[19];

vector<int> BV[19];
int B[MAXN][19], BT[19][19];

int A[MAXN];

int N, Q;

bool check(int lne, int e) {
	int k = int(lower_bound(allv(BV[lne]), e) - BV[lne].begin());
	if(sz(BV[lne]) <= k || BV[lne][k] != e) return false;
	return true;
}

bool f(int s, int e) {
	priority_queue<pii, vector<pii>, greater<pii>> PQ;
	fill(dp, dp+19, INF);
	for(int i = 0; i < 19; i++) {
		if(!(A[s] & (1<<i))) continue;
		dp[i] = s;
		PQ.push(pii(s, i));
	}
	for(int idx, lne; !PQ.empty();) {
		tie(idx, lne) = PQ.top(); PQ.pop();
		if(dp[lne] < idx) continue;
		if(check(lne, e)) return true;
		for(int i = 0; i < 19; i++) {
			int nxt = B[idx][i];
			if(e < nxt || dp[i] <= nxt) continue;
			dp[i] = nxt;
			PQ.push(pii(nxt, i));
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	for(int i = 1; i <= N; i++) cin >> A[i];

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 19; j++)
			if(A[i] & (1<<j)) BV[j].eb(i);
	}
	fill(B[N+1], B[N+1]+19, INF);
	fill(BT[0], BT[18]+19, INF);
	for(int i = N; i; i--) {
		fill(B[i], B[i]+19, INF);
		for(int j = 0; j < 19; j++) {
			if(!(A[i] & (1<<j))) continue;
			B[i][j] = i;
		}
		for(int j = 0; j < 19; j++) {
			if(!(A[i] & (1<<j))) continue;
			for(int k = 0; k < 19; k++)
				upmin(B[i][k], BT[j][k]);
		}
		for(int j = 0; j < 19; j++) {
			if(!(A[i] & (1<<j))) continue;
			for(int k = 0; k < 19; k++) {
				upmin(BT[j][k], B[i][k]);
			}
		}
	}

	for(int s, e; Q--;) {
		cin >> s >> e;
		puts(f(s, e) ? "Shi" : "Fou");
	}

	return 0;
}
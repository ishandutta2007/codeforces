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

const int MAXN = 1000055;

struct SEG {
	ll dmx[MAXN*4], dp[MAXN*4];
	int di[MAXN*4];

	void init(int i, int s, int e) {
		di[i] = s;
		if(s == e) return;
		int m = (s+e) >> 1;
		init(i<<1, s, m);
		init(i<<1|1, m+1, e);
	}

	void prop(int i, int s, int e) {
		if(!dp[i]) return;
		dmx[i] += dp[i];
		if(s != e) {
			dp[i<<1] += dp[i];
			dp[i<<1|1] += dp[i];
		}
		dp[i] = 0;
	}

	void upd(int i, int s, int e, int p, int q, ll r) {
		prop(i, s, e); if(q < p || e < p || q < s) return;
		if(p <= s && e <= q) {
			dp[i] += r;
			prop(i, s, e);
			return;
		}
		int m = (s+e) >> 1;
		upd(i<<1, s, m, p, q, r);
		upd(i<<1|1, m+1, e, p, q, r);
		tie(dmx[i], di[i]) = max(pli(dmx[i<<1], di[i<<1]), pli(dmx[i<<1|1], di[i<<1|1]));
	}
	
	pli get(int i, int s, int e, int p, int q) {
		prop(i, s, e); if(q < p || e < p || q < s) return {-INFLL, -1};
		if(p <= s && e <= q) return {dmx[i], di[i]};
		int m = (s+e) >> 1;
		return max(get(i<<1, s, m, p, q), get(i<<1|1, m+1, e, p, q));
	}
} seg;

vector<int> EV[MAXN];

vector<int> XV;
int A[MAXN], B[MAXN], C[MAXN];
int AI[MAXN], BI[MAXN];

ll Ans;
int N, K, AnsS = INF, AnsE = INF;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i];
		if(B[i] < A[i]) swap(A[i], B[i]);
		XV.eb(A[i]); XV.eb(B[i]);
	}
	sorv(XV); univ(XV); K = sz(XV);

	seg.init(1, 0, K-1);
	for(int i = 0; i < K; i++) seg.upd(1, 0, K-1, i, i, XV[i]);
	for(int i = 0; i < N; i++) {
		AI[i] = int(lower_bound(allv(XV), A[i]) - XV.begin());
		BI[i] = int(lower_bound(allv(XV), B[i]) - XV.begin());
		EV[BI[i]].eb(i);
	}

	for(int e = 0; e < K; e++) {
		for(int i : EV[e]) {
			seg.upd(1, 0, K-1, 0, AI[i], C[i]);
		}
		ll mx; int mxi;
		tie(mx, mxi) = seg.get(1, 0, K-1, 0, e);
		mx -= XV[e];
		if(Ans < mx) {
			Ans = mx;
			AnsS = XV[mxi];
			AnsE = XV[e];
		}
	}

	cout << Ans << endl << AnsS << ' ' << AnsS << ' ' << AnsE << ' ' << AnsE << endl;
	return 0;
}
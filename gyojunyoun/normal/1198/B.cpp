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

const int MAXN = 200055;

struct SEG {
	int lz[MAXN*4], dt[MAXN];

	void prop(int i, int s, int e) {
		if(s == e) {
			upmax(dt[s], lz[i]);
			lz[i] = 0;
			return;
		}
		upmax(lz[i<<1], lz[i]);
		upmax(lz[i<<1|1], lz[i]);
		lz[i] = 0;
	}
	void upd(int i, int s, int e, int x, int r) {
		prop(i, s, e);
		if(x < s || e < x) return;
		if(s == e) {
			dt[x] = r;
			lz[i] = 0;
			return;
		}
		int m = (s+e) >> 1;
		upd(i<<1, s, m, x, r);
		upd(i<<1|1, m+1, e, x, r);
	}
	void propall(int i, int s, int e) {
		prop(i, s, e); if(s == e) return;
		int m = (s+e) >> 1;
		propall(i<<1, s, m);
		propall(i<<1|1, m+1, e);
	}
} seg;

int N, Q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 1, c; i <= N; i++) {
		cin >> c;
		seg.upd(1, 1, N, i, c);
	}
	cin >> Q;
	for(int t, a, b; Q--;) {
		cin >> t >> a;
		if(1 == t) {
			cin >> b;
			seg.upd(1, 1, N, a, b);
		} else {
			upmax(seg.lz[1], a);
		}
	}

	seg.propall(1, 1, N);

	for(int i = 1; i <= N; i++) printf("%d ", seg.dt[i]);
	puts("");
	return 0;
}
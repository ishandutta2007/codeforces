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
bool issame(const ld& x, const ld& y) { return isZero(x-y); }
ll pw(ll n) { return n*n; }

struct CIR {
	int x, y, r;
	void in() {
		scanf("%d%d%d", &x, &y, &r);
	}
};

vector<CIR> V;

CIR cir[3];
bool chk[3];

int N, Ans = 1;

bool issect(CIR a, CIR b) {
	if(pw(a.r+b.r) < pw(a.x-b.x) + pw(a.y-b.y)) return false;
	if(pw(a.x-b.x) + pw(a.y-b.y) < pw(a.r-b.r)) return false;
	return true;
}
void insec(CIR _a, CIR _b, vector<pdd> &V) {
	ld a = _a.x, b = _a.y, r = _a.r, c = _b.x, d = _b.y, s = _b.r;
	ld e = c - a, f = d - b, p = sqrt(e * e + f * f), k = (p * p + r * r - s * s) / (2 * p);
	ld x1 = a + (e * k) / p + (f / p) * sqrt(r * r - k * k);
	ld y1 = b + (f * k) / p - (e / p) * sqrt(r * r - k * k);
	ld x2 = a + (e * k) / p - (f / p) * sqrt(r * r - k * k);
	ld y2 = b + (f * k) / p + (e / p) * sqrt(r * r - k * k);
	V.pb(pdd(x1, y1)); V.pb(pdd(x2, y2));
}

void doit() {
	for(int _ = 0; _ < 10; _++) {
		for(int i = 0; i < N; i++) if(!chk[i]) {
			if(V.empty()) {
				V.pb(cir[i]);
				Ans++;
				chk[i] = true;
				continue;
			}

			bool flag = false;
			for(auto &v : V) if(issect(v, cir[i])) flag = true;
			if(!flag) continue;


			chk[i] = true;

			vector<pdd> Q;
			for(auto &v : V) if(issect(v, cir[i])) insec(v, cir[i], Q);
			sort(allv(Q), [&](pdd a, pdd b) -> bool {
				if(!issame(a.first, b.first)) return a.first < b.first;
				return a.second < b.second;
			});
			Q.erase(unique(allv(Q), [&](pdd a, pdd b) -> bool {
				return issame(a.first, b.first) && issame(a.second, b.second);
			}), Q.end());

			Ans += sz(Q);
			V.pb(cir[i]);
		}
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) cir[i].in();
	for(;;) {
		doit();

		int hi = -1;
		for(int i = 0; i < N; i++) if(!chk[i]) hi = i;
		if(hi < 0) break;

		V.clear();
	}
	printf("%d\n", Ans);
	return 0;
}
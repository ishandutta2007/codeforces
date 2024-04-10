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
typedef double ld;
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

typedef priority_queue<pli, vector<pli>, greater<pli>> PQTYPE;

void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }

const int MAXN = 100005;
const int MAXM = 100005;

PQTYPE Q;
vector<pii> G[MAXN];
vector<int> V;
ll d[MAXN];
int rd[MAXN];

int N, M;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 0, a, b, c; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		fg(G, a, b, c);
	}
	fill(d, d+MAXN, INFLL); fill(rd, rd+MAXN, -1);
	Q.push({0ll, 1}); d[1] = 0;
	for(; !Q.empty();) {
		int idx; ll dst; tie(dst, idx) = Q.top(); Q.pop();
		if(d[idx] < dst) continue;
		for(pii &e : G[idx]) {
			const ll ndst = dst + e.second;
			const int nidx = e.first;
			if(d[nidx] < ndst) continue;
			d[nidx] = ndst; rd[nidx] = idx;
			Q.push({ndst, nidx});
		}
	}
	if(INFLL <= d[N]) { puts("-1"); return 0; }
	for(int idx = N; 1 < idx; idx = rd[idx]) V.pb(idx);
	V.pb(1); revv(V);
	for(int v : V) printf("%d ", v); puts("");
	return 0;
}
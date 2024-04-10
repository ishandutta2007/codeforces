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

const int MAXN = 35;

vector<pll> V;

int A[MAXN], B[MAXN];

ll Ans = INFLL;
int N, L;

int main() {
	scanf("%d%d", &N, &L);
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	iota(B, B+N, 0); sort(B, B+N, [&](int a, int b) -> bool {
		return (ll)A[a] * (1ll << b) < (ll)A[b] * (1ll << a);
	});
	V.pb({L, 0});
	for(int i = 0; i < N; i++) {
		const int idx = B[i];
		for(int j = sz(V)-1; ~j; j--) {
			pll &v = V[j];
			ll n = (v.first + (1ll << idx) - 1) / (1ll << idx);
			upmin(Ans, v.second + n * A[idx]);

			n = v.first / (1ll << idx);
			V.pb({v.first - n * (1ll << idx), v.second + n * A[idx]});
		}
		sorv(V);
		vector<pll> Q;
		for(int j = 0; j < sz(V); j++) {
			if(Q.empty() || Q.back().second > V[j].second) {
				Q.pb(V[j]);
			}
		}
		swap(V, Q); clv(Q);
	}
	printf("%lld\n", Ans);
	return 0;
}
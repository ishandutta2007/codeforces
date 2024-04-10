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
ld size(pll p) { return sqrt((ld)(p.first*p.first + p.second*p.second)); }

const int MAXN = 100005;

pll P[MAXN];
ld DA[MAXN], DB[MAXN];
vector<pair<ld, int>> VA, VB;

ld Ans;
pll A, B, C;
int N;

int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &A.first, &A.second, &B.first, &B.second, &C.first, &C.second);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%lld%lld", &P[i].first, &P[i].second);
		DA[i] = size(P[i]-A) - size(P[i]-C);
		DB[i] = size(P[i]-B) - size(P[i]-C);
		Ans += size(P[i]-C);

		VA.pb({DA[i], i}); VB.pb({DB[i], i});
	}
	Ans *= 2;

	if(1 == N) {
		Ans = min(size(P[1]-A), size(P[1]-B)) + size(P[1]-C);
	} else {
		swap(VA[0], *min_element(allv(VA)));
		swap(VB[0], *min_element(allv(VB)));
		swap(VA[1], *min_element(VA.begin()+1, VA.end()));
		swap(VB[1], *min_element(VB.begin()+1, VB.end()));

		ld t = INFLL;
		if(VA[0].first <= 0) {
			ld x = VA[0].first + min((ld)0, VB[0].second == VA[0].second ? VB[1].first : VB[0].first);
			upmin(t, x);
		}
		if(VB[0].first <= 0) {
			ld x = VB[0].first + min((ld)0, VA[0].second == VB[0].second ? VA[1].first : VA[0].first);
			upmin(t, x);
		}
		upmin(t, VA[0].first);
		upmin(t, VB[0].first);

		Ans += t;
	}

	printf("%.10lf\n", (double)Ans);
	return 0;
}
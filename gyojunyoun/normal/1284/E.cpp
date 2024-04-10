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

const int MAXN = 5055;

pll P[MAXN];
int O[MAXN];

ll Ans;
int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++) cin >> P[i].fi >> P[i].se;

	for(int i = N; i--;) {
		for(int j = 0, k = 0; j < N; j++) if(j != i) O[k++] = j;
		sort(O, O+N-1, [&](int a, int b) {
			bool af = P[i].fi < P[a].fi || P[i].fi == P[a].fi && P[i].se < P[a].se;
			bool bf = P[i].fi < P[b].fi || P[i].fi == P[b].fi && P[i].se < P[b].se;
			if(af != bf) return af;
			return ccw(P[i], P[a], P[b]) > 0;
		});
		int n = N-1;
		for(int i = 0; i < n; i++) O[i+n] = O[i];

		ll ret = 0;
		for(int s = 0, e = 0, n = N-1; s < n; s++) {
			for(; e < s+n && ccw(P[O[s]], P[i], P[O[e]]) <= 0; e++);
			int t = e-s - 1;
			ret += ll(t) * (t-1) / 2;
		}
		ret = ll(n) * (n-1) * (n-2) / 6 - ret;
		ret = ret * (N-4);
		Ans += ret;
	}

	cout << Ans/2 << endl;
	return 0;
}
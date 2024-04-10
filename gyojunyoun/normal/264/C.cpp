#include <bits/stdc++.h>
//#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
#define rf(x) (x)=0;while(*p<48)im=*p++=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
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
static unsigned char str[5500055], *p=str;
static bool im=false;

const int MAXN = 100055;

ll mx1, mx2;
int mxc1, mxc2;

ll dp[MAXN];
int A[MAXN], B[MAXN];

int N, Q, CA, CB;

ll f() {
	ll ret = 0;
	fill(dp, dp+N+1, -INFLL);
	mx1 = mx2 = -INFLL;
	mxc1 = -1; mxc2 = -1;

	for(int i = 1; i <= N; i++) {
		int c = B[i];

		ll tmp = ll(A[i]) * CB + max(0ll, (c == mxc1 ? mx2 : mx1));
		ll tp = ll(A[i]) * CA + dp[c];
		if(tmp < tp) tmp = tp;

		if(ret < tmp) ret = tmp;
		
		if(mx1 < tmp) {
			if(mxc1 != c) {
				mx2 = mx1;
				mxc2 = mxc1;
			}
			mx1 = tmp;
			mxc1 = c;
		} else if(mx2 < tmp) {
			if(mxc1 != c) {
				mx2 = tmp;
				mxc2 = c;
			}
		}
		if(dp[c] < tmp) dp[c] = tmp;
	}

	return ret;
}

int main() {
	fread(str, 1, 5500055, stdin);

	rf(N) rf(Q)
	for(int i = 1; i <= N; i++) { rf(A[i]) }
	for(int i = 1; i <= N; i++) { rf(B[i]) }

	for(; Q--;) {
		rf(CA) rf(CB)
		printf("%lld\n", f());
	}
	return 0;
}
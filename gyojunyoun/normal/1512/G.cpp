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

const int MAXX = 10000005;

int Ans[MAXX];

int dp[MAXX];

int main() {
	dp[1] = 1;
	for(int i = 2; i < MAXX; i += 2) dp[i] = 2;
	for(int i = 3; i*i < MAXX; i += 2) if(!dp[i]) {
		dp[i] = i;
		for(int j = i*i; j < MAXX; j += i+i) dp[j] = i;
	}

	for(int i = 2; i < MAXX; i++) {
		int p = dp[i];
		if(!p) p = i;

		if(p == i) {
			dp[i] = i+1;
			continue;
		}

		int n = 0, x = i;
		while(0 == x%p) {
			x /= p;
			n++;
		}

		if(1 == x) {
			if((MAXX+p-1)/p <= dp[i/p]) dp[i] = MAXX;
			else dp[i] = dp[i/p] * p + 1;
			continue;
		}

		if((MAXX+dp[x]-1)/dp[x] <= dp[i/x]) dp[i] = MAXX;
		else dp[i] = dp[x] * dp[i/x];
	}

	for(int i = MAXX-1; i; i--)
		if(dp[i] < MAXX) Ans[dp[i]] = i;

	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	for(; T--;) {
		int n; cin >> n;

		n = Ans[n];

		if(!n) cout << "-1\n";
		else cout << n << '\n';
	}

	return 0;
}
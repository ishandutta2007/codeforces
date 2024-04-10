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

const int MAXN = 100005;
const int SQRN = 330;

bitset<MAXN> isnp;

int dp[MAXN], dm[MAXN];

int A[MAXN];

int N;

void f(vector<int> &V, int x) {
	V.clear();
	if(!(x&1)) {
		for(V.eb(2); !(x&1); x >>= 1);
	}
	for(int i = 3; i <= x && i < SQRN; i += 2)
		if(!isnp[i] && !(x%i))
			for(V.eb(i), x /= i; !(x%i); x /= i);
	if(1 < x) V.eb(x);
}

int main() {
	ios::sync_with_stdio(false);
	isnp[0] = isnp[1] = true;
	for(int i = 4; i < MAXN; i += 2) isnp[i] = true;
	for(int i = 3; i*i < MAXN; i += 2) if(!isnp[i])
		for(int j = i*i; j < MAXN; j += i<<1) isnp[j] = true;

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];

	for(int i = 1; i <= N; i++) {
		int &ret = dp[i]; ret = 1;
		vector<int> V; f(V, A[i]);
		for(int v : V) upmax(ret, dm[v] + 1);
		for(int v : V) upmax(dm[v], ret);
	}

	cout << *max_element(dp+1, dp+N+1) << endl;
	return 0;
}
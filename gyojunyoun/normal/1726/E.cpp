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

const int MOD = 998244353;

const int MAXN = 300'055;

ll pw(ll n, ll k) {
	ll r = 1;
	while(k) {
		if(k&1) r = r * n % MOD;
		n = n * n % MOD;
		k >>= 1;
	}
	return r;
}
ll inv(ll n) { return pw(n, MOD-2); }

ll F[MAXN], RF[MAXN];

ll A[MAXN], B[MAXN];

int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	F[0] = F[1] = 1;
	for(int i = 2; i < MAXN; i++) F[i] = F[i-1] * i % MOD;
	for(int i = 0; i < MAXN; i++) RF[i] = inv(F[i]);

	A[0] = A[1] = 1;
	for(int i = 2; i < MAXN; i++)
		A[i] = (A[i-1] + ll(i-1) * A[i-2]) % MOD;
	
	B[0] = 1;
	for(int i = 1; i < MAXN; i++)
		B[i] = 2ll * ll(i+i-1) * B[i-1] % MOD;

	int T; cin >> T;
	while(T--) {
		cin >> N;

		ll r = 0;

		for(int k = 0; k+k <= N; k++) if(!(k&1)) {
			ll t = F[N-k] * RF[k] % MOD * RF[N-k-k] % MOD;
			r = (r + t * B[k/2] % MOD * A[N-k-k]) % MOD;
		}

		cout << r << '\n';
	}

	return 0;
}
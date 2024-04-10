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
void fuk() { puts("-1"); exit(0); }

ll A[5555], B[5555];

ll P, K;
int N;

int main() {
	cin >> P >> K;
	B[0] = P;
	for(; P < 0 || K <= P; N++) {
		ll &ret = A[N];
		ll s = -(P/K), e = 1ll - P/K;
		for(; K*e < K-P; e++);
		for(; K-P <= K*e; e--);
		for(; -P <= K*s; s--);
		for(; K*s < -P; s++);
		if(e < s) fuk();
		if(s <= 0 && 0 <= e) ret = 0;
		else if(abs(s) < abs(e)) ret = s;
		else ret = e;

		P = ret;
	}

	for(int i = 0; i < N; i++) {
		B[i] += A[i]*K;
		B[i+1] += A[i];
	}
	for(N = 5554; 0 <= N && !B[N]; N--);
	printf("%d\n", N+1);
	for(int i = 0; i <= N; i++) printf("%lld ", B[i]);
	puts("");
	return 0;
}
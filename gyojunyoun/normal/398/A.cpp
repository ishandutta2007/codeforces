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
ll pw(ll n) { return n*n; }

ll Ans = -INFLL; int AnsC;
int N, M;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M;

	if(!M) {
		printf("%lld\n", ll(N) * N);
		for(int i = 1; i <= N; i++) putchar('o');
		puts("");
		return 0;
	}
	if(!N) {
		printf("%lld\n", -ll(M) * M);
		for(int i = 1; i <= M; i++) putchar('x');
		puts("");
		return 0;
	}

	if(1 == M) {
		printf("%lld\n", pw(N) - 1);
		for(int i = 0; i < N; i++) putchar('o');
		puts("x");
		return 0;
	}

	for(int g = 1; g <= M; g++) {
		if(N < g-1) continue;

		int s = M/g, lc = M - s*g;
		ll t = pw(s) * (g-lc) + pw(s+1) * lc;
		t = -t;

		if(1 == g) t += pw(N);
		else t += (g-2) + pw(N-g+2);

		if(Ans < t) {
			Ans = t;
			AnsC = g;
		}
	}

	printf("%lld\n", Ans);
	int g = AnsC;
	if(1 == AnsC) {
		putchar('x');
		for(int i = 1; i <= N; i++) putchar('o');
		puts("");
	} else {
		vector<int> V;
		int s = M/g, lc = M - s*g;
		for(int i = 0; i < g; i++) V.eb(s);
		for(int i = 0; i < lc; i++) V[i]++;

		for(int i = 0; i < g; i++) {
			for(int j = 0; j < V[i]; j++) putchar('x');
			if(!i) {
				for(int j = 0; j < N-g+2; j++) putchar('o');
			} else if(i != g-1) {
				putchar('o');
			}
		}
		puts("");
	}
	return 0;
}
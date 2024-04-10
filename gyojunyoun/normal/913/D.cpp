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

const int MAXN = 200005;

int A[MAXN], B[MAXN];

int N, T;

bool f(int C, bool isp = false) {
	vector<pii> V; // {time, idx}
	for(int i = 1; i <= N; i++) {
		if(A[i] < C) continue;
		V.pb({B[i], i});
	}
	sorv(V);
	if(sz(V) < C) return false;
	ll sum = 0;
	for(int i = 0; i < C; i++) {
		sum += V[i].first;
	}
	if(T < sum) return false;
	if(isp) {
		for(int i = 0; i < C; i++) {
			printf("%d ", V[i].second);
		}
		puts("");
	}
	return true;
}
void getAns() {
	int s = 0, e = N; for(int m; s < e;) {
		m = (s+e+1)/2;
		if(f(m)) s = m;
		else e = m-1;
	}
	printf("%d\n%d\n", s, s);
	f(s, true);
}
int main() {
	scanf("%d%d", &N, &T);
	for(int i = 1; i <= N; i++) scanf("%d%d", &A[i], &B[i]);
	getAns();
	return 0;
}
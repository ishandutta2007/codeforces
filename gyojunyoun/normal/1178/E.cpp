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

const int MAXN = 1000055;

int L[MAXN][3], R[MAXN][3];

vector<int> AnsV;

char A[MAXN];
int B[MAXN];

int N;

void f(int s, int e) {
	if(s > e) return;
	if(s == e) {
		AnsV.eb(B[s]);
		return;
	}
	if(B[s] == B[e]) {
		AnsV.eb(B[s]);
		f(s+1, e-1);
		AnsV.eb(B[e]);
		return;
	}

	int as = R[s][0], ae = L[e][0];
	int bs = R[s][1], be = L[e][1];
	int cs = R[s][2], ce = L[e][2];
	int al = ae-as+1, bl = be-bs+1, cl = ce-cs+1;
	int mx = max({al, bl, cl});
	if(mx <= 0) return;
	if(mx == al) f(as, ae);
	else if(mx == bl) f(bs, be);
	else f(cs, ce);
}

int main() {
	scanf(" %s", A+1);
	N = strlen(A+1);

	for(int i = 1; i <= N; i++) {
		if('a' == A[i]) B[i] = 0;
		else if('b' == A[i]) B[i] = 1;
		else B[i] = 2;
	}

	fill(L[0], L[0]+3, -INF);
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 3; j++)
			L[i][j] = L[i-1][j];
		L[i][B[i]] = i;
	}

	fill(R[N+1], R[N+1]+3, INF);
	for(int i = N; i; i--) {
		for(int j = 0; j < 3; j++)
			R[i][j] = R[i+1][j];
		R[i][B[i]] = i;
	}

	f(1, N);
	
	if(sz(AnsV) >= N/2) {
		for(int v : AnsV) putchar('a' + v);
		puts("");
	} else {
		puts("IMPOSSIBLE");
	}
	return 0;
}
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
const ld EPS = (ld)1e-9;
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

int E[MAXN][2];
int D[MAXN];

char A[MAXN][6];
int B[MAXN], C[MAXN];

int N;

void dfs1(int i) {
	if('I' == A[i][0]) {
		D[i] = B[i];
		return;
	}
	if('N' == A[i][0]) {
		dfs1(B[i]);
		D[i] = !D[B[i]];
		return;
	}
	dfs1(B[i]); dfs1(C[i]);
	if('A' == A[i][0]) {
		D[i] = D[B[i]] & D[C[i]];
	} else if('O' == A[i][0]) {
		D[i] = D[B[i]] | D[C[i]];
	} else {
		D[i] = D[B[i]] ^ D[C[i]];
	}
}

void dfs2(int i) {
	if('I' == A[i][0]) return;
	if('N' == A[i][0]) {
		E[B[i]][0] = E[i][1];
		E[B[i]][1] = E[i][0];
		dfs2(B[i]);
		return;
	}
	if('A' == A[i][0]) {
		E[B[i]][0] = E[i][0];
		E[B[i]][1] = E[i][D[C[i]]];
		E[C[i]][0] = E[i][0];
		E[C[i]][1] = E[i][D[B[i]]];
	} else if('O' == A[i][0]) {
		E[B[i]][0] = E[i][D[C[i]]];
		E[B[i]][1] = E[i][1];
		E[C[i]][0] = E[i][D[B[i]]];
		E[C[i]][1] = E[i][1];
	} else {
		E[B[i]][0] = E[i][D[C[i]]];
		E[B[i]][1] = E[i][D[C[i]]^1];
		E[C[i]][0] = E[i][D[B[i]]];
		E[C[i]][1] = E[i][D[B[i]]^1];
	}
	dfs2(B[i]); dfs2(C[i]);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf(" %s%d", A[i], &B[i]);
		if('I' != A[i][0] && 'N' != A[i][0]) scanf("%d", &C[i]);
	}

	dfs1(1);

	E[1][0] = 0; E[1][1] = 1;
	dfs2(1);

	for(int i = 1; i <= N; i++) if('I' == A[i][0])
		putchar(E[i][!B[i]] ? '1' : '0');
	puts("");
	return 0;
}
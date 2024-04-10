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

const int MAXN = 100055;

int L[MAXN][2], R[MAXN][2];
bool DL[2][MAXN], DR[2][MAXN];
char A[MAXN];

int N, K;

bool f(int s, int e, int x) {
	if(INF <= L[s-1][!x]) {
		if(DR[x][e+1]) return true;
	}
	if(R[e+1][!x] < 0) {
		if(DL[x][s-1]) return true;
	}
	return false;
}

int main() {
	scanf("%d%d %s", &N, &K, A+1);
	L[0][0] = INF; L[0][1] = INF;
	for(int i = 1; i <= N; i++) {
		L[i][0] = L[i-1][0];
		L[i][1] = L[i-1][1];
		if('0' == A[i]) {
			upmin(L[i][0], i);
		} else {
			upmin(L[i][1], i);
		}
	}
	R[N+1][0] = R[N+1][1] = -INF;
	for(int i = N; i; i--) {
		R[i][0] = R[i+1][0];
		R[i][1] = R[i+1][1];
		if('0' == A[i]) {
			upmax(R[i][0], i);
		} else {
			upmax(R[i][1], i);
		}
	}

	for(int s = 1, e = K; e <= N; s++, e++) {
		// 0
		if(INF <= L[s-1][1] && R[e+1][1] < 0) {
			puts("tokitsukaze");
			return 0;
		}
		// 1
		if(INF <= L[s-1][0] && R[e+1][0] < 0) {
			puts("tokitsukaze");
			return 0;
		}
	}

	{
		int i = 1;
		DL[0][0] = true;
		for(; i <= N; i++) {
			if('1' == A[i]) break;
			DL[0][i] = true;
		}
		for(int t = 0; i <= N && t < K; i++, t++) {
			DL[0][i] = true;
		}
		i = 1;
		DL[1][0] = true;
		for(; i <= N; i++) {
			if('0' == A[i]) break;
			DL[1][i] = true;
		}
		for(int t = 0; i <= N && t < K; i++, t++) {
			DL[1][i] = true;
		}
	}
	{
		int i = N;
		DR[0][N+1] = true;
		for(; i; i--) {
			if('1' == A[i]) break;
			DR[0][i] = true;
		}
		for(int t = 0; i && t < K; i--, t++) {
			DR[0][i] = true;
		}
		i = N;
		DR[1][N+1] = true;
		for(; i; i--) {
			if('0' == A[i]) break;
			DR[1][i] = true;
		}
		for(int t = 0; i && t < K; i--, t++) {
			DR[1][i] = true;
		}
	}

	bool flag = false;
	for(int s = 1, e = K; e <= N; s++, e++) {
		if(f(s, e, 0) && f(s, e, 1)) continue;
		puts("once again");
		return 0;
	}
	puts("quailty");

	return 0;
}
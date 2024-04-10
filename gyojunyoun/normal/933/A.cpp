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

const int MAXN = 2005;

int B[MAXN][MAXN], C[MAXN][MAXN];
int D[MAXN][MAXN], E[MAXN][MAXN];
int A[MAXN];

int N, Ans;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) for(int j = i; j <= N; j++) {
		B[i][j] = B[i][j-1]; C[i][j] = C[i][j-1];
		(1 == A[j] ? B[i][j] : C[i][j])++;
	}
	for(int i = 1; i <= N; i++) {
		vector<int> V;
		for(int j = i; j <= N; j++) {
			auto it = upper_bound(allv(V), A[j]);
			if(V.end() == it) V.pb(A[j]);
			else *it = A[j];
			D[i][j] = sz(V);
		}
	}
	for(int i = N; i; i--) {
		vector<int> V;
		for(int j = i; j; j--) {
			auto it = upper_bound(allv(V), A[j]);
			if(V.end() == it) V.pb(A[j]);
			else *it = A[j];
			E[j][i] = sz(V);
		}
	}
	for(int i = 1; i <= N; i++) for(int j = i; j <= N; j++) {
		int t = B[1][i-1] + B[i][j] + max(B[j+1][N], D[j+1][N]);
		upmax(t, B[1][i-1] + max(E[i][j], C[i][j]) + C[j+1][N]);
		upmax(t, max(D[1][i-1], C[1][i-1]) + C[i][j] + C[j+1][N]);
		upmax(Ans, t);
	}
	printf("%d\n", Ans);
	return 0;
}
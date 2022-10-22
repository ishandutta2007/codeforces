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

int dp[2005][2005];

int C[2005];
char A[2005], B[505];

int Ans[2005];
int N, M, K, L;

int main() {
	scanf(" %s %s", A+1, B+1);
	N = strlen(A+1);
	M = strlen(B+1);

	for(int i = M; i <= N; i++) {
		if(A[i] != B[M]) {
			C[i] = C[i-1];
			continue;
		}
		int j = i; for(int k = M; j; j--) {
			if(A[j] == B[k]) k--;
			if(!k) break;
		}
		C[i] = j;
	}

	for(int i = N; i;) {
		if(!C[i]) break;
		i = C[i] - 1;
		K++;
	}
	if(!K) {
		for(int i = N+1; i--;) printf("0 ");
		puts("");
		exit(0);
	}

	fill(dp[0]+1, dp[0]+K+1, INF);
	for(int i = 1; i <= N; i++) {
		fill(dp[i]+1, dp[i]+K+1, INF);
		if(!C[i]) continue;
		for(int j = K; j; j--)
			dp[i][j] = min(dp[i-1][j], dp[C[i]-1][j-1] + i-C[i]+1 - M);
	}

	L = N - M*K;
	for(int i = 0; i <= K; i++) upmax(Ans[dp[N][i]], i);
	for(int i = 1; i <= L; i++) upmax(Ans[i], Ans[i-1]);
	for(int i = L+1; i <= N; i++) Ans[i] = (N-i) / M;

	for(int i = 0; i <= N; i++) cout << Ans[i] << ' ';
	cout << endl;
	return 0;
}
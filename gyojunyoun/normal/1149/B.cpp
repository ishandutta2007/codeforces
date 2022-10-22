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

const int MAXN = 100055;

int dp[255][255][255];

int B[MAXN][26];
char A[MAXN];
char C[3][555]; int Cn[3];

int N, Q;

int main() {
	scanf("%d%d", &N, &Q);
	scanf(" %s", A+1);

	fill(B[N+1], B[N+1]+26, INF);
	for(int i = N; i; i--) {
		for(int j = 0; j < 26; j++)
			B[i][j] = B[i+1][j];
		B[i][A[i]-'a'] = i;
	}

	for(int i = 0; i < 255; i++) for(int j = 0; j < 255; j++)
		fill(dp[i][j], dp[i][j]+255, INF);
	dp[0][0][0] = 0;

	for(int qi = 0; qi < Q; qi++) {
		char type;
		int idx;
		char c;

		scanf(" %c %d", &type, &idx);
		idx--;
		if('+' == type) {
			scanf(" %c", &c);
			Cn[idx]++;
			C[idx][Cn[idx]] = c;

			if(0 == idx) {
				for(int i = 0; i <= Cn[1]; i++) for(int j = 0; j <= Cn[2]; j++) {
					int &ret = dp[Cn[0]][i][j];
					ret = INF;
					if(dp[Cn[0]-1][i][j] < N)
						upmin(ret, B[dp[Cn[0]-1][i][j]+1][C[0][Cn[0]]-'a']);
					if(i && dp[Cn[0]][i-1][j] < N)
						upmin(ret, B[dp[Cn[0]][i-1][j]+1][C[1][i]-'a']);
					if(j && dp[Cn[0]][i][j-1] < N)
						upmin(ret, B[dp[Cn[0]][i][j-1]+1][C[2][j]-'a']);
				}
			} else if(1 == idx) {
				for(int i = 0; i <= Cn[0]; i++) for(int j = 0; j <= Cn[2]; j++) {
					int &ret = dp[i][Cn[1]][j];
					ret = INF;
					if(dp[i][Cn[1]-1][j] < N)
						upmin(ret, B[dp[i][Cn[1]-1][j]+1][C[1][Cn[1]]-'a']);
					if(i && dp[i-1][Cn[1]][j] < N)
						upmin(ret, B[dp[i-1][Cn[1]][j]+1][C[0][i]-'a']);
					if(j && dp[i][Cn[1]][j-1] < N)
						upmin(ret, B[dp[i][Cn[1]][j-1]+1][C[2][j]-'a']);
				}
			} else {
				for(int i = 0; i <= Cn[0]; i++) for(int j = 0; j <= Cn[1]; j++) {
					int &ret = dp[i][j][Cn[2]];
					ret = INF;
					if(dp[i][j][Cn[2]-1] < N)
						upmin(ret, B[dp[i][j][Cn[2]-1]+1][C[2][Cn[2]]-'a']);
					if(i && dp[i-1][j][Cn[2]] < N)
						upmin(ret, B[dp[i-1][j][Cn[2]]+1][C[0][i]-'a']);
					if(j && dp[i][j-1][Cn[2]] < N)
						upmin(ret, B[dp[i][j-1][Cn[2]]+1][C[1][j]-'a']);
				}
			}
		} else {
			Cn[idx]--;
		}

		puts(dp[Cn[0]][Cn[1]][Cn[2]] <= N ? "YES" : "NO");
	}

	return 0;
}
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

inline void add(int &a, int b) { a += b; if(MOD <= a) a -= MOD; }

int DP[1005][1005][3][4];

char A[1005], B[1005];

int N, M;

void run() {
	cin >> A >> B;
	N = strlen(A);
	M = strlen(B);

	for(int i = 0; i <= N; i++) for(int j = 0; j <= M; j++) {
		DP[i][j][0][0] = 1;
		
		for(int c = 0; c < 3; c++) {
			char last = c ? (1 == c ? (i ? A[i-1] : '0') : (j ? B[j-1] : '0')) : '0';

			for(int d = 0; d < 4; d++) {
				if(i < N && last != A[i]) add(DP[i+1][j][1][d|1], DP[i][j][c][d]);
				if(j < M && last != B[j]) add(DP[i][j+1][2][d|2], DP[i][j][c][d]);
			}
		}
	}

	int Ans = 0;
	for(int i = 0; i <= N; i++) for(int j = 0; j <= M; j++) {
		for(int c = 0; c < 3; c++)
			add(Ans, DP[i][j][c][3]);
	}

	cout << Ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T = 1;
	for(; T--;) run();

	return 0;
}
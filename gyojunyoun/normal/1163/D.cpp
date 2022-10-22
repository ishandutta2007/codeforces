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

int dp[1005][55][55];

int BT[55][26], CT[55][26];

char A[1005], B[55], C[55];
int AL, BL, CL, Ans = -INF;

int main() {
	scanf(" %s %s %s", A+1, B+1, C+1);
	AL = int(strlen(A+1));
	BL = int(strlen(B+1));
	CL = int(strlen(C+1));

	for(int i = 0; i < BL; i++) {
		string str = "";
		for(int j = 1; j <= i; j++) str += B[j];

		for(int j = 0; j < 26; j++) {
			string nstr = str;
			nstr += ('a' + j);
			for(int l = i+1; l; l--) {
				if(i == BL-1 && j+'a' == B[BL] && l == BL) continue;
				bool flag = false;
				for(int s = l-1, e = i; 0 <= s && 0 <= e; s--, e--) {
					if(B[s+1] != nstr[e]) {
						flag = true;
						break;
					}
				}
				if(!flag) {
					BT[i][j] = l;
					break;
				}
			}
		}
	}
	for(int i = 0; i < CL; i++) {
		string str = "";
		for(int j = 1; j <= i; j++) str += C[j];

		for(int j = 0; j < 26; j++) {
			string nstr = str;
			nstr += ('a' + j);
			for(int l = i+1; l; l--) {
				if(i == CL-1 && j+'a' == C[CL] && l == CL) continue;
				bool flag = false;
				for(int s = l-1, e = i; 0 <= s && 0 <= e; s--, e--) {
					if(C[s+1] != nstr[e]) {
						flag = true;
						break;
					}
				}
				if(!flag) {
					CT[i][j] = l;
					break;
				}
			}
		}
	}

	fill(dp[0][0], dp[1004][54]+55, -INF);
	dp[0][0][0] = 0;

	for(int i = 0; i < AL; i++) {
		for(int j = 0; j < BL; j++) {
			for(int k = 0; k < CL; k++) {
				int t = dp[i][j][k];
				if(t <= -INF) continue;

				if('*' != A[i+1]) {
					int nj = BT[j][A[i+1]-'a'];
					int nk = CT[k][A[i+1]-'a'];
					int nt = t;
					if(j == BL-1 && A[i+1] == B[BL]) nj = BL;
					if(k == CL-1 && A[i+1] == C[CL]) nk = CL;
					if(nj == BL) {
						nt++;
						nj = BT[BL-1][B[BL]-'a'];
					}
					if(nk == CL) {
						nt--;
						nk = CT[CL-1][C[CL]-'a'];
					}
					upmax(dp[i+1][nj][nk], nt);
				} else {
					for(int c = 0; c < 26; c++) {
						int nj = BT[j][c];
						int nk = CT[k][c];
						int nt = t;
						if(j == BL-1 && 'a'+c == B[BL]) nj = BL;
						if(k == CL-1 && 'a'+c == C[CL]) nk = CL;
						if(nj == BL) {
							nt++;
							nj = BT[BL-1][B[BL]-'a'];
						}
						if(nk == CL) {
							nt--;
							nk = CT[CL-1][C[CL]-'a'];
						}
						upmax(dp[i+1][nj][nk], nt);
					}
				}
			}
		}
	}

	for(int i = 0; i < BL; i++) for(int j = 0; j < CL; j++)
		upmax(Ans, dp[AL][i][j]);
	
	cout << Ans << endl;
	return 0;
}
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
void fg(vector<int> G[], int a, int b) { G[a].eb(b); G[b].eb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].eb(b, c); G[b].eb(a, c); }

int dp[1<<12], C[1<<12];

vector<int> A[2005];
int B[2005][12];

int T, H, W;

void run() {
	cin >> H >> W;
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) cin >> B[j][i];
	for(int i = 0; i < W; i++) {
		rotate(B[i], max_element(B[i], B[i]+H), B[i]+H);
		A[i].clear();
		for(int j = 0; j < H; j++)
			A[i].eb(B[i][j]);
	}
	sort(A, A+W); reverse(A, A+W);

	memset(dp, 0, (1<<H)*4);
	for(int i = 0; i < min(H, W); i++) {
		memset(C, 0, (1<<H)*4);
		for(int key = 1<<H; key--;) {
			int sum = 0;
			for(int j = 0; j < H; j++)
				if(key & (1<<j)) sum += A[i][j];
			C[key] = sum;
		}
		for(int key = 1<<H; key--;) {
			vector<int> V;
			V.eb(key);
			for(int j = 0, nkey = key; j < H; j++) {
				nkey <<= 1;
				if(nkey & (1<<H)) {
					nkey ^= 1<<H;
					nkey |= 1;
				}
				V.eb(nkey);
			}
			int mx = 0;
			for(int v : V) upmax(mx, C[v]);
			for(int v : V) C[v] = mx;
		}

		for(int key = 1<<H; key--;) {
			upmax(dp[key], C[key]);
			for(int i = key; i; i = key & (i-1))
				upmax(dp[key], C[key ^ i] + dp[i]);
		}
	}

	cout << dp[(1<<H)-1] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	for(; T--;) run();
	return 0;
}
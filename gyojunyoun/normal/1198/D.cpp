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

int D[52][52][52][52];

int B[55][55];
char A[55][55];

int N;

int getSum(int sy, int sx, int ey, int ex) {
	sy--; sx--;
	return B[ey][ex] - B[sy][ex] - B[ey][sx] + B[sy][sx];
}

int f(int sy, int sx, int ey, int ex) {
	if(sy > ey || sx > ex) return 0;
	int &ret = D[sy][sx][ey][ex];
	if(ret < INF) return ret;
	if(!getSum(sy, sx, ey, ex)) {
		ret = 0;
		return 0;
	}
	ret = max(ey-sy+1, ex-sx+1);
	for(int i = sy; i <= ey; i++)
		upmin(ret, f(sy, sx, i, ex) + f(i+1, sx, ey, ex));
	for(int j = sx; j <= ex; j++)
		upmin(ret, f(sy, sx, ey, j) + f(sy, j+1, ey, ex));
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf(" %s", A[i]+1);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++)
		B[i][j] = B[i-1][j] + B[i][j-1] - B[i-1][j-1] + ('#' == A[i][j]);

	fill(D[0][0][0], D[51][51][51]+52, INF);
	cout << f(1, 1, N, N) << endl;
	return 0;
}
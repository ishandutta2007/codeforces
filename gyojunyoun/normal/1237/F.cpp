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

const int MOD = 998244353;
const int MAXH = 3605;
const int MAXW = 3605;

inline void add(int &a, int b) { a += b; if(MOD <= a) a -= MOD; }

ll pw(ll n, ll k) {
	ll r = 1; for(; k; k >>= 1) {
		if(k&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}
ll inv(ll n) { return pw(n, MOD-2); }

ll DF[MAXH], IDF[MAXH];

ll com(int a, int b) {
	if(b < 0 || a < b) return 0;
	return DF[a] * IDF[b] % MOD * IDF[a-b] % MOD;
}

int DA[MAXH][MAXH/2], DB[MAXW][MAXW/2];

bitset<MAXH> A;
bitset<MAXW> B;

ll Ans;
int H, W, N, FHC, FWC;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	DF[0] = 1;
	for(int i = 1; i < MAXH; i++) DF[i] = DF[i-1] * i % MOD;
	IDF[MAXH-1] = inv(DF[MAXH-1]);
	for(int i = MAXH-2; 0 <= i; i--) IDF[i] = IDF[i+1] * (i+1) % MOD;

	cin >> H >> W >> N;
	for(int sy, ey, sx, ex; N--;) {
		cin >> sy >> sx >> ey >> ex;
		A[sy] = A[ey] = true;
		B[sx] = B[ex] = true;
	}
	FHC = H - A.count();
	FWC = W - B.count();

	DA[0][0] = DA[1][0] = 1;
	for(int i = 2; i <= H; i++) {
		if(A[i]) {
			for(int j = 0; j*2 <= i; j++)
				DA[i][j] = DA[i-1][j];
			continue;
		}
		for(int j = 0; j*2 <= i; j++) {
			DA[i][j] = DA[i-1][j];
			if(j && !A[i-1]) add(DA[i][j], DA[i-2][j-1]);
		}
	}

	DB[0][0] = DB[1][0] = 1;
	for(int i = 2; i <= W; i++) {
		if(B[i]) {
			for(int j = 0; j*2 <= i; j++)
				DB[i][j] = DB[i-1][j];
			continue;
		}
		for(int j = 0; j*2 <= i; j++) {
			DB[i][j] = DB[i-1][j];
			if(j && !B[i-1]) add(DB[i][j], DB[i-2][j-1]);
		}
	}

	for(int a = 0; a*2 <= FHC; a++) for(int b = 0; a*2+b <= FHC; b++) {
		if(a+b*2 > FWC) continue;
		ll ret = DA[H][a];
		ret = ret * com(FHC-a*2, b) % MOD;
		ret = ret * DB[W][b] % MOD;
		ret = ret * com(FWC-b*2, a) % MOD;
		ret = ret * DF[a] % MOD * DF[b] % MOD;
		Ans = (Ans + ret) % MOD;
	}

	cout << (Ans % MOD) << endl;
	return 0;
}
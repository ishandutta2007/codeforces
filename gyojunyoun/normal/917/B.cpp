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

const int MAXN = 105;

vector<pii> G[MAXN];

bool d[MAXN][MAXN][30][2], chk[MAXN][MAXN][30][2];

int N, M;

bool f(int i, int j, int c, int turn) {
	if(chk[i][j][c][turn]) {
		return d[i][j][c][turn];
	}
	chk[i][j][c][turn] = true;
	bool &ret = d[i][j][c][turn];

	if(!turn) {
		for(auto &e : G[i]) {
			if(e.second < c) continue;
			if(!f(e.first, j, e.second, 1))
				return (ret = false);
		}
		ret = true;
	} else {
		for(auto &e : G[j]) {
			if(e.second < c) continue;
			if(f(i, e.first, e.second, 0))
				return (ret = true);
		}
		ret = false;
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 0, a, b; i < M; i++) {
		char c; scanf("%d%d %c", &a, &b, &c);
		G[a].pb({b, c-'a'});
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			putchar(f(i, j, 0, 0) ? 'B' : 'A');
		}
		putchar('\n');
	}
	return 0;
}
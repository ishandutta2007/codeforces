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

const int MAXN = 100055;
const int SQRN = 330;

int A[MAXN];
int DP[MAXN];

int alpha[SQRN];
bitset<SQRN> chk;

int N, Q;

void recal(int bi, int bs, int be) {
	for(int i = bs; i <= be; i++) {
		DP[i] = max(1, i - A[i] - alpha[bi]);
		if((DP[i]-1) / SQRN == bi) DP[i] = DP[DP[i]];
		else DP[i] = i;
	}
}

void upd(int s, int e, int c) {
	for(int bi = 0; bi < SQRN; bi++) {
		int bs = bi * SQRN + 1;
		int be = min(N, (bi + 1) * SQRN);

		if(e < bs) break;
		if(be < s) continue;

		if(s <= bs && be <= e) {
			bool flag = alpha[bi] < SQRN;

			alpha[bi] += c;

			if(flag) {
				recal(bi, bs, be);
			} else if(!chk[bi]) {
				chk[bi] = true;
				for(int i = bs; i <= be; i++) DP[i] = i;
			}
		} else {
			for(int i = max(s, bs); i <= min(e, be); i++)
				A[i] += c;

			recal(bi, bs, be);
		}
	}
}

int get(int x, int y) {
	if(x > y) swap(x, y);
	if(x == y) return x;
	if(1 == x) return 1;

	int xbi = (x-1) / SQRN;
	int ybi = (y-1) / SQRN;

	while(x != y) {
		// x < y

		if(xbi < ybi) {
			y = DP[y];
			y -= A[y] + alpha[ybi];
			if(y < 1) y = 1;
			ybi = (y-1) / SQRN;
		} else {
			// xbi == ybi

			if(DP[x] == DP[y]) {
				break;
			}

			x = DP[x];
			x -= A[x] + alpha[xbi];
			if(x < 1) x = 1;
			xbi = (x-1) / SQRN;

			y = DP[y];
			y -= A[y] + alpha[ybi];
			if(y < 1) y = 1;
			ybi = (y-1) / SQRN;
		}

		if(x > y) {
			swap(x, y);
			swap(xbi, ybi);
		}
	}

	// xbi == ybi
	while(x != y) {
		if(x > y) {
			swap(x, y);
			swap(xbi, ybi);
		}

		// x < y

		y -= A[y] + alpha[ybi];
		if(y < 1) y = 1;
		ybi = (y-1) / SQRN;
	}

	return x;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;

	A[1] = 0;
	for(int i = 2; i <= N; i++) {
		cin >> A[i];
		A[i] = i - A[i];
	}

	DP[1] = 1;
	for(int i = 2; i <= N; i++) {
		DP[i] = i - A[i];
		if((DP[i]-1) / SQRN == (i-1) / SQRN) DP[i] = DP[i - A[i]];
		else DP[i] = i;
	}

	for(int t, a, b, c; Q--;) {
		cin >> t >> a >> b;
		if(2 == t) {
			cout << get(a, b) << '\n';
		} else {
			cin >> c;

			upd(a, b, c);
		}
	}

	return 0;
}
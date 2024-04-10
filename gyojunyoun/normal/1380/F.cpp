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
void fuk() {  puts("-1"); exit(0); }

const int MAXN = 500055;
const int MOD = 998244353;

inline void add(int &a, int b) { a += b; if(MOD <= a) a -= MOD; }

struct NOD {
	int xx, xy, xc;
	int yx, yy, yc;
} nod[MAXN*4];

int A[MAXN];

int N, Q;

void merge(NOD &t, NOD &l, NOD &r) {
	t.xc = (ll(l.xc) * r.xx + ll(l.yc) * r.xy + r.xc) % MOD;
	t.xx = (ll(l.xx) * r.xx + ll(l.yx) * r.xy) % MOD;
	t.xy = (ll(l.xy) * r.xx + ll(l.yy) * r.xy) % MOD;

	t.yc = (ll(l.xc) * r.yx + ll(l.yc) * r.yy + r.yc) % MOD;
	t.yx = (ll(l.xx) * r.yx + ll(l.yx) * r.yy) % MOD;
	t.yy = (ll(l.xy) * r.yx + ll(l.yy) * r.yy) % MOD;
}

void calone(int i, int s) {
	nod[i].xx = 0;
	nod[i].xy = 1;
	nod[i].xc = 0;

	nod[i].yx = 0;
	nod[i].yy = A[s]+1;
	nod[i].yc = 0;

	if(1 < s && A[s-1] && 10*A[s-1] + A[s] < 19) {
		add(nod[i].yx, 19 - (10*A[s-1] + A[s]));
	}
}

void initcal(int i, int s, int e) {
	if(s == e) {
		calone(i, s);
		return;
	}

	int m = s+e >> 1;

	initcal(i<<1, s, m);
	initcal(i<<1|1, m+1, e);

	merge(nod[i], nod[i<<1], nod[i<<1|1]);
}

void upd(int i, int s, int e, int x) {
	if(x < s || e < x) return;
	if(s == e) {
		calone(i, x);
		return;
	}

	int m = s+e >> 1;
	upd(i<<1, s, m, x);
	upd(i<<1|1, m+1, e, x);

	merge(nod[i], nod[i<<1], nod[i<<1|1]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;

	{
		string S;
		cin >> S;
		for(int i = 1; i <= N; i++)
			A[i] = S[i-1] & 15;
	}

	initcal(1, 1, N);

	for(int a, b; Q--;) {
		cin >> a >> b;
		A[a] = b;
		upd(1, 1, N, a);
		if(a < N) upd(1, 1, N, a+1);

		cout << nod[1].yy << '\n';
	}
	return 0;
}
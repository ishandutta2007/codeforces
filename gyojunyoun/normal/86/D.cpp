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

const int MAXN = 200055;
const int MAXQ = 200055;
const int MAXX = 1000055;
const int SQRN = 450;

struct QUR {
	QUR(int s, int e, int idx)
		: s(s), e(e), idx(idx) {}
	int s, e, idx;

	bool operator < (const QUR &t) const {
		if(s/SQRN != t.s/SQRN)
			return s/SQRN < t.s/SQRN;
		return e < t.e;
	}
};

vector<QUR> EV;

int B[MAXX];
ll C;
int Si, Ei;

int A[MAXN];

ll Ans[MAXQ];
int N, Q;

void push(int x) {
	C -= ll(x) * B[x] * B[x];
	B[x]++;
	C += ll(x) * B[x] * B[x];
}
void pop(int x) {
	C -= ll(x) * B[x] * B[x];
	B[x]--;
	C += ll(x) * B[x] * B[x];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1, a, b; i <= Q; i++) {
		cin >> a >> b;
		EV.eb(a, b, i);
	}
	sorv(EV);

	Si = 1; Ei = 0;
	for(auto &ev : EV) {
		int s = ev.s, e = ev.e;
		for(; Ei < e;) push(A[++Ei]);
		for(; s < Si;) push(A[--Si]);
		for(; e < Ei;) pop(A[Ei--]);
		for(; Si < s;) pop(A[Si++]);
		Ans[ev.idx] = C;
	}

	for(int i = 1; i <= Q; i++)
		cout << Ans[i] << '\n';
	return 0;
}
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

const int MOD = 1000000009;
const int MAXN = 300055;
const int SQRN = 550;

inline void add(int &a, int b) { a += b; if(MOD <= a) a -= MOD; }

int F[MAXN], FS[MAXN];

vector<pii> QV;
int A[MAXN], B[MAXN], S[MAXN];

int N, Q;

int f(int s, int e) {
	int ret = S[e]; add(ret, MOD-S[s-1]);
	for(auto &ev : QV) {
		int a, b; tie(a, b) = ev;
		if(e < a || b < s) continue;
		if(e < b) b = e;
		add(ret, FS[b-a+1]);
		if(a < s) add(ret, MOD-FS[s-a]);
	}
	return ret;
}

void rel() {
	for(auto &ev : QV) {
		int a, b; tie(a, b) = ev;
		if(a == b) {
			add(B[a], 1);
			add(B[a+1], MOD-1);
			add(B[a+2], MOD-1);
		} else {
			add(B[a], 1);
			add(B[b+1], MOD-F[b-a+2]);
			add(B[b+2], MOD-F[b-a+1]);
		}
	}
	for(int i = 1; i <= N; i++) {
		add(B[i], B[i-1]);
		if(1 < i) add(B[i], B[i-2]);
		add(A[i], B[i]);
	}
	memset(B, 0, (N+4)<<2);
	QV.clear();
	for(int i = 1; i <= N; i++) {
		S[i] = S[i-1];
		add(S[i], A[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	F[1] = F[2] = 1;
	for(int i = 3; i < MAXN; i++) {
		F[i] = F[i-1];
		add(F[i], F[i-2]);
	}
	for(int i = 1; i < MAXN; i++) {
		FS[i] = FS[i-1];
		add(FS[i], F[i]);
	}

	cin >> N >> Q;
	for(int i = 1; i <= N; i++) cin >> A[i];

	for(int bt = SQRN, t, a, b; Q--; bt++) {
		if(SQRN <= bt) { rel(); bt = 0; }
		cin >> t >> a >> b;
		if(1 == t) QV.eb(a, b);
		else cout << f(a, b) << '\n';
	}
	return 0;
}
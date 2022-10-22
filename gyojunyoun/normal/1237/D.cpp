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
const int MX = 131072;

struct MXSEG {
	ll d[MX*2];

	void init() { fill(d, d+MX*2, 0); }
	void upd(int x, ll r) {
		for(x += MX; x; x >>= 1)
			upmax(d[x], r);
	}
	ll get(int s, int e) {
		ll r = 0; for(s += MX, e += MX; s <= e; s >>= 1, e >>= 1) {
			if(s&1) upmax(r, d[s++]);
			if(~e&1) upmax(r, d[e--]);
		}
		return r;
	}
} mxseg;

int B[MAXN], C[MAXN];
ll A[MAXN];

ll Ans[MAXN];
int N, _SI, K;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	_SI = int(max_element(A+1, A+N+1) - A);
	rotate(A+1, A+_SI, A+N+1);

	K = 1; for(ll mx = A[1]; K < N && mx <= A[K+1]*2; K++);

	for(int i = 1; i <= N; i++) mxseg.upd(i, A[i]);
	for(int i = 2; i <= N; i++) {
		int s = 1, e = i; for(int m; s < e;) {
			m = s+e >> 1;
			if(mxseg.get(m, i) <= A[i]*2) e = m;
			else s = m+1;
		}
		B[i] = s;
	}
	mxseg.init();

	for(int i = 1; i <= N; i++) mxseg.upd(i, B[i]);
	for(int i = 1; i <= N; i++) {
		int s = i, e = N; for(int m; s < e;) {
			m = s+e+1 >> 1;
			if(mxseg.get(i+1, m) <= i) s = m;
			else e = m-1;
		}
		C[i] = s;
	}

	Ans[1] = N == K ? -1 : K;
	for(int i = 2; i <= N; i++) {
		if(C[i] < N) {
			Ans[i] = C[i] - i + 1;
		} else {
			if(N == K) Ans[i] = -1;
			else {
				Ans[i] = N-i+1 + K;
			}
		}
	}

	if(1 != _SI) rotate(Ans+1, Ans+N+2-_SI, Ans+N+1);
	for(int i = 1; i <= N; i++) cout << Ans[i] << ' ';
	cout << '\n';
	return 0;
}
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

const int MAXN = 100005;
const int SQRN = 320;

int A[SQRN][MAXN];
deque<int> B[SQRN];

int N, Q;

void f(int p, int q) {
	if(p >= q) return;
	int pi = p / SQRN, qi = q / SQRN;
	int pj = p % SQRN, qj = q % SQRN;
	if(pi == qi) {
		rotate(B[pi].begin()+pj, B[pi].begin()+qj, B[pi].begin()+qj+1);
		return;
	}
	for(int i = pi, x; i < qi; i++) {
		x = B[i].back();
		B[i].pop_back();
		B[i+1].emplace_front(x);
		A[i][x]--; A[i+1][x]++;
	}
	{
		int x = B[qi][qj+1];
		B[qi].erase(B[qi].begin()+qj+1);
		B[pi].insert(B[pi].begin()+pj, x);
		A[qi][x]--; A[pi][x]++;
	}
}

int f(int p, int q, int x) {
	int pi = p / SQRN, qi = q / SQRN;
	int pj = p % SQRN, qj = q % SQRN;
	int ret = 0;
	if(pi == qi) {
		for(int i = pj; i <= qj; i++)
			if(B[pi][i] == x) ret++;
		return ret;
	}
	for(int i = sz(B[pi])-1; pj <= i; i--)
		if(B[pi][i] == x) ret++;
	for(int i = qj; 0 <= i; i--)
		if(B[qi][i] == x) ret++;
	for(int i = pi+1; i < qi; i++) ret += A[i][x];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 0, c, bi; i < N; i++) {
		cin >> c;
		bi = i / SQRN;
		A[bi][c]++;
		B[bi].eb(c);
	}

	cin >> Q;
	for(int t, a, b, c, pv = 0; Q--;) {
		cin >> t >> a >> b;
		if(2 == t) cin >> c;
		a = (a+pv-1) % N;
		b = (b+pv-1) % N;
		c = (c+pv-1) % N + 1;
		if(a > b) swap(a, b);

		if(1 == t) f(a, b);
		else cout << (pv = f(a, b, c)) << '\n';
	}
	return 0;
}
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define fi first
#define se second
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

int G[1<<20][2];

int A[1<<18];

int N, K;

void push(int i, int k, int x) {
	if(!k) return;

	int &v = G[i][!!(x&k)];
	if(!v) v = ++K;
	push(v, k >> 1, x);
}

int get(int i, int k, int x, int v) {
	if(!k) return v;

	int t = G[i][!(x&k)];
	if(t) return get(t, k>>1, x, v | ((!(x&k)) ? k : 0));

	t = G[i][!!(x&k)];
	return get(t, k>>1, x, v | ((!!(x&k)) ? k : 0));
}

void run() {
{
	int a, b;
	cin >> a >> b;
	N = b+1;
}

	for(int i = 0; i < N; i++) cin >> A[i];


	K = 1;

	for(int i = N; i--;) {
		push(1, 1<<16, A[i]);
	}

	for(int i = N; i--;) {
		int x = A[i];

		int r = get(1, 1<<16, x, 0);
		r ^= x;

		if(r == N-1) {
			cout << x << '\n';
		fill(G[0], G[K+2]+1, 0);
			return;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while(T--) run();
	return 0;
}
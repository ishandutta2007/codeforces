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

const int MAXN = 50055;

struct NOD {
	NOD(int idx, pii pos, int x) : idx(idx), x(x), pos(pos) {}
	int idx, x;
	pii pos;


	bool operator < (const NOD &t) const {
		if(pos != t.pos) return pos < t.pos;
		return x > t.x;
	}
};

int A[MAXN], B[MAXN], C[MAXN];
int O[MAXN];

int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i];
	iota(O, O+N+1, 0);
	sort(O+1, O+N+1, [&](int a, int b) {
		if(A[a] != A[b]) return A[a] < A[b];
		if(B[a] != B[b]) return B[a] < B[b];
		return C[a] < C[b];
	});

	vector<NOD> V;
	for(int s = 1, e; s <= N; s = e) {
		for(e = s+1; e <= N && A[O[s]] == A[O[e]]; e++);
		for(int oi = s, i; oi < e; oi++) {
			i = O[oi];
			V.eb(i, pii(B[i], C[i]), A[i]);
		}
		sorv(V);
		vector<NOD> TV;
		int n = sz(V);
		for(int p = 0, q; p < n; p = q) {
			for(q = p+1; q < n && B[V[p].idx] == B[V[q].idx]; q++);
			int oi = p; for(int a, b; oi+1 < q;) {
				a = V[oi].idx; b = V[oi+1].idx;
				cout << a << ' ' << b << '\n';
				oi += 2;
			}
			if(oi < q) TV.eb(V[oi]);
		}
		swap(V, TV); TV.clear();
		sort(allv(V), [&](const NOD &a, const NOD &b) {
			pii ap = {a.pos.second, a.pos.first}, bp = {b.pos.second, b.pos.first};
			if(ap != bp) return ap < bp;
			return a.x > b.x;
		});
		n = sz(V);
		for(int p = 0, q; p < n; p = q) {
			for(q = p+1; q < n && C[V[p].idx] == C[V[q].idx]; q++);
			int oi = p; for(int a, b; oi+1 < q;) {
				a = V[oi].idx; b = V[oi+1].idx;
				cout << a << ' ' << b << '\n';
				oi += 2;
			}
			if(oi < q) TV.eb(V[oi]);
		}
		swap(V, TV); TV.clear();
		sorv(V);
		for(; 1 < sz(V);) {
			cout << V.back().idx << ' ';
			V.pop_back();
			cout << V.back().idx << '\n';
			V.pop_back();
		}
	}

	return 0;
}
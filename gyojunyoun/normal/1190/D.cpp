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
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }

const int MAXN = 200055;

struct BIT {
	int d[MAXN];
	void upd(int x, int r) {
		for(x += 5; x < MAXN; x += rb(x))
			d[x] += r;
	}
	int get(int x) {
		int r = 0; for(x += 5; x; x -= rb(x))
			r += d[x];
		return r;
	}
	int get(int s, int e) {
		return s > e ? 0 : get(e)-get(s-1);
	}
} bit;

vector<int> EV[MAXN];

vector<int> AV, BV;
int A[MAXN], B[MAXN];

ll Ans;
int N;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		swap(A[i], B[i]);
		AV.eb(A[i]);
		BV.eb(B[i]);
	}
	sorv(AV); univ(AV);
	sorv(BV); univ(BV);
	for(int i = 1; i <= N; i++) {
		A[i] = int(lower_bound(allv(AV), A[i]) - AV.begin()) + 1;
		B[i] = int(lower_bound(allv(BV), B[i]) - BV.begin()) + 1;
	}

	for(int i = 1; i <= N; i++) EV[A[i]].eb(B[i]);

	set<int> PQX;
	for(int y = N; y; y--) {
		auto &V = EV[y];
		if(V.empty()) continue;
		sorv(V); univ(V);
		for(int v : V) {
			auto it = PQX.find(v);
			if(PQX.end() != it) continue;
			bit.upd(v, 1);
			PQX.insert(v);
		}
		for(int i = 0, n = sz(V), x; i < n; i++) {
			x = V[i];
			ll l = i ? bit.get(V[i-1]+1, x) : bit.get(x);
			ll r = bit.get(N+1);
			r -= bit.get(x);
			r++;

			Ans += l*r;
		}
	}

	cout << Ans << endl;
	return 0;
}
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

const int MAXN = 200055;

int ud[MAXN];
int A[MAXN];
int AS[MAXN], AE[MAXN];

int N, Q, Ans;

int uf(int i) { return ud[i] == i ? i : (ud[i] = uf(ud[i])); }
void uf(int a, int b) { ud[uf(b)] = uf(a); }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	iota(ud, ud+MAXN, 0);
	fill(AS, AS+MAXN, INF);

	cin >> N >> Q;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		upmin(AS[A[i]], i);
		upmax(AE[A[i]], i);
	}
	for(int i = 0; i < MAXN; i++) {
		int s = AS[i], e = AE[i];
		if(s > e) continue;
		for(int t = s;;) {
			t = uf(t);
			if(e <= t) break;
			uf(t+1, t);
		}
	}

	vector<pii> V;
	for(int i = 1;;) {
		int e = uf(i);
		V.eb(i, e);
		i = e+1;
		if(N < i) break;
	}

	for(auto &v : V) {
		int s, e; tie(s, e) = v;
		map<int, int> MP;
		for(int i = s; i <= e; i++) MP[A[i]]++;
		int mx = 0;
		for(auto &v : MP) upmax(mx, v.second);
		Ans += e-s+1 - mx;
	}

	cout << Ans << endl;
	return 0;
}
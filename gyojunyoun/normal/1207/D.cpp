#include <bits/stdc++.h>
//#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
#define rf(x) (x)=0;while(*p<48)im=*p++=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
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

const int MOD = 998244353;
const int MAXN = 300055;

inline void add(int &a, int b) { a += b; if(MOD <= a) a -= MOD; }

int A[MAXN], B[MAXN], C[MAXN];
int DF[MAXN];

int N, Ans;

void process() {
	{
		int b = 1;
		for(int oi = 1, i; oi <= N; oi++) {
			i = C[oi];
			if(B[i] < b) return;
			b = B[i];
		}
	}

	unordered_map<ll, int> MP;
	for(int i = 1; i <= N; i++) MP[ll(A[i]) * MAXN + B[i]]++;
	int ret = 1;
	for(auto &v : MP) ret = ll(ret) * DF[v.second] % MOD;
	ret = (MOD-ret) % MOD;
	add(Ans, ret);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	DF[0] = 1;
	for(int i = 1; i < MAXN; i++) DF[i] = ll(DF[i-1]) * i % MOD;

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i] >> B[i];

	{
		int ret = 1;
		for(int i = 1; i <= N; i++) C[A[i]]++;
		for(int i = 1; i <= N; i++) ret = ll(ret) * DF[C[i]] % MOD;
		add(Ans, ret);
	}
	{
		int ret = 1;
		memset(C, 0, MAXN<<2);
		for(int i = 1; i <= N; i++) C[B[i]]++;
		for(int i = 1; i <= N; i++) ret = ll(ret) * DF[C[i]] % MOD;
		add(Ans, ret);
	}

	iota(C, C+N+1, 0); sort(C+1, C+N+1, [&](int a, int b) {
		return A[a] != A[b] ? A[a] < A[b] : B[a] < B[b];
	});

	process();

	Ans = DF[N] - Ans;
	cout << ((Ans % MOD + MOD) % MOD) << endl;
	return 0;
}
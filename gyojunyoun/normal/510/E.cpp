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
inline void fuk() { puts("Impossible"); exit(0); }

const int MAXX = 20055;

bitset<MAXX> isnp;

vector<int> G[205];
int D[105];

int A[205], B[105], C[105];

vector<pii> EV;
bitset<205> chk;

vector<vector<int>> Ans;
int N, K;

bool f(int i) {
	if(chk[i]) return false; chk[i] = true;
	for(int v : G[i]) if(!D[v] || f(D[v])) return D[v] = i;
	return false;
}

void dfs(int i, vector<int> &V) {
	V.eb(i); chk[i] = true;
	for(int v : G[i]) if(!chk[v]) {
		dfs(v, V);
		return;
	}
}

int main() {
	isnp[0] = isnp[1] = true;
	for(int i = 4; i < MAXX; i += 2) isnp[i] = true;
	for(int i = 3; i*i < MAXX; i += 2) if(!isnp[i])
		for(int j = i*i; j < MAXX; j += i+i) isnp[j] = true;

	cin >> N;
	if(N & 1) fuk();
	for(int i = 1; i <= N; i++) cin >> A[i];

	{
		int b = 0, c = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] & 1) B[++b] = i;
			else C[++c] = i;
		}
		if(b != c) fuk();
	}
	K = N >> 1;

	for(int i = K; i; i--) for(int j = K; j; j--)
		if(!isnp[A[B[i]] + A[C[j]]]) G[i].eb(j);
	
	for(int i = K; i; i--) {
		chk.reset();
		if(!f(i)) fuk();
	}
	for(int i = K; i; i--) {
		EV.eb(C[i], B[D[i]]);
		G[D[i]].erase(find(allv(G[D[i]]), i));
	}
	memset(D, 0, 105*4);
	for(int i = K; i; i--) {
		chk.reset();
		if(!f(i)) fuk();
	}
	for(int i = K; i; i--) {
		EV.eb(C[i], B[D[i]]);
		G[i].clear();
	}
	for(auto &e : EV) fg(G, e.fi, e.se);

	chk.reset();
	for(int i = N; i; i--) if(!chk[i]) {
		Ans.eb();
		dfs(i, Ans.back());
	}

	cout << sz(Ans) << '\n';
	for(auto &V : Ans) {
		cout << sz(V);
		for(int v : V) cout << ' ' << v;
		cout << '\n';
	}
	return 0;
}
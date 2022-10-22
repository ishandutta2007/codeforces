#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
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

vector<int> G[MAXN];

int dep[MAXN], dh[MAXN], dl[MAXN];
bitset<MAXN> chk;

int Ans[MAXN];
int N, K, Rt;

void f(int i, int c, int dc) {
	chk[i] = true;
	Ans[i] = c;
	c += dc;
	if(c < 0) c += K;
	if(K <= c) c -= K;
	for(int v : G[i]) if(!chk[v]) f(v, c, dc);
}

void dfs(int i) {
	chk[i] = true;
	dh[i] = 1;
	for(int v : G[i]) if(!chk[v]) {
		dep[v] = dep[i] + 1;
		dfs(v);
		upmax(dh[i], dh[v] + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for(int i = 1, a, b; i < N; i++) {
		cin >> a >> b;
		fg(G, a, b);
	}

	dep[1] = 1; dfs(1);
	Rt = int(max_element(dep+1, dep+N+1) - dep);
	chk.reset();
	dep[Rt] = 1; dfs(Rt);
	int LI = int(max_element(dep+1, dep+N+1) - dep);
	{
		chk.reset();
		vector<int> V; V.eb(LI);
		for(int v; !V.empty();) {
			v = V.back(); V.pop_back();
			chk[v] = true;
			for(int i : G[v]) if(!chk[i]) {
				chk[i] = true;
				dl[i] = dl[v] + 1;
			}
		}
	}

	if(K > 2) {
	for(int i = 1; i <= N; i++) {
		vector<int> V;
		for(int v : G[i]) {
			if(dep[v] < dep[i]) {
				V.eb(max(dep[i]-1, dl[i]));
				continue;
			}
			V.eb(dh[v]);
		}
		sorv(V); revv(V);
		if(sz(V) < 3) continue;
		if(min({V[0]+V[1], V[0]+V[2], V[1]+V[2]})+1 >= K) {
			puts("No");
			exit(0);
		}
	}
	}

	vector<int> Path;
	for(int i = LI;;) {
		Path.eb(i);
		int nxt = -1;
		for(int v : G[i]) if(dep[v] < dep[i]) nxt = v;
		if(nxt < 0) break;
		i = nxt;
	}

	chk.reset();
	int CA = Path[sz(Path)/2], CB = Path[sz(Path)/2-1];
	G[CA].erase(find(allv(G[CA]), CB));
	G[CB].erase(find(allv(G[CB]), CA));

	f(CA, K-1, -1); f(CB, 0, 1);

	puts("Yes");
	for(int i = 1; i <= N; i++)
		printf("%d ", Ans[i] + 1);
	puts("");
	return 0;
}
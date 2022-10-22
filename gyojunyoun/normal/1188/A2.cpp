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

const int MAXN = 1005;

struct NOD {
	NOD(int a, int b, int c)
		: a(a), b(b), c(c) {}
	int a, b, c;

	void prt() {
		cout << a << ' ' << b << ' ' << c << '\n';
	}
};

vector<pii> G[MAXN];
int GI[MAXN], GJ[MAXN];
vector<int> LV[MAXN];

int prt[MAXN];
bitset<MAXN> isL;

vector<NOD> AnsV;
int N, Rt;

bitset<MAXN> chk;
void push(int a, int b, int c) {
	AnsV.eb(a, b, c);

	chk.reset();
	int p = -1;
	for(int v = a; v; v = prt[v]) chk[v] = true;
	for(int v = b;; v = prt[v])
		if(chk[v]) { p = v; break; }
	
	for(int v = a; v != p; v = prt[v]) {
		G[v][GI[v]].second -= c;
		G[prt[v]][GJ[v]].second -= c;
	}
	for(int v = b; v != p; v = prt[v]) {
		G[v][GI[v]].second -= c;
		G[prt[v]][GJ[v]].second -= c;
	}
}

void solve(int p, int v, int &cost) {
	if(isL[v]) {
		push(Rt, v, cost);
		return;
	}
	for(auto &ed : G[v]) {
		int u = ed.first;
		if(p == u) continue;
		solve(v, u, ed.second);
	}
	int a = LV[v][0], b = LV[v].back(), _cost = cost;
	push(a, Rt, _cost/2);
	push(b, Rt, _cost/2);
	push(a, b, -_cost/2);
}

void predfs(int i, int p) {
	if(i != Rt && 1 == sz(G[i])) {
		isL[i] = true;
		LV[i].eb(i);
	}

	for(auto &ed : G[i]) {
		int v = ed.first;
		if(v == p) continue;
		prt[v] = i;
		predfs(v, i);
		for(int w : LV[v])
			LV[i].eb(w);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 1, a, b, c; i < N; i++) {
		cin >> a >> b >> c;
		fg(G, a, b, c);
	}
	for(int i = 1; i <= N; i++) if(2 == sz(G[i])) {
		puts("NO");
		exit(0);
	}

	for(int i = 1; i <= N; i++)
		if(1 == sz(G[i])) Rt = i;
	predfs(Rt, -1);

	for(int i = 1; i <= N; i++) {
		for(int j = 0, dg = sz(G[i]); j < dg; j++) {
			if(G[i][j].first == prt[i]) {
				GI[i] = j;
			} else {
				GJ[G[i][j].first] = j;
			}
		}
	}

	solve(Rt, G[Rt][0].first, G[Rt][0].second);

	cout << "YES\n" << sz(AnsV) << '\n';
	for(auto &v : AnsV) v.prt();
	return 0;
}
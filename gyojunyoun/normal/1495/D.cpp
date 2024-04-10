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

const int MOD = 998244353;

int ud[405];

vector<int> G[405];
int D[405][405];

int dfo[405], dup[405];


int A[605], B[605];

int Ans[405][405];

int N, M;

int uf(int i) { return i == ud[i] ? i : (ud[i] = uf(ud[i])); }
void uf(int a, int b) { ud[uf(b)] = uf(a); }


vector<int> T[405];
pii DP[405]; // {dist, from}
int CNT[405];
int solve3(int RA, int RB) {
	vector<int> Path;

	{
		int v = RA;
		for(;;) {
			Path.eb(v);
			if(RB == v) break;

			for(int u : G[v]) {
				if(D[RB][u] + 1 == D[RB][v]) {
					v = u;
					break;
				}
			}
		}
	}

	for(int i = N; i; i--) T[i].clear();

	fill(DP, DP+N+1, pii(0, 0));
	fill(CNT, CNT+N+1, 0);

	queue<int> PQ;
	bitset<405> chk;
	chk.reset();

	{
		for(int i = 1, n = sz(Path); i < n; i++)
			fg(T, Path[i-1], Path[i]);
	}

	for(int v : Path) {
		DP[v] = {0, v};
		CNT[v] = 1;
		chk[v] = true;

		PQ.emplace(v);
	}

	for(int v, dst, from; !PQ.empty();) {
		v = PQ.front(); PQ.pop();
		tie(dst, from) = DP[v];
		dst++;

		for(int u : G[v]) if(!chk[u]) {
			chk[u] = true;
			DP[u] = {dst, from};
			PQ.emplace(u);
			fg(T, u, v);
		}
	}

	for(int i = 1; i <= N; i++) if(i == uf(i) && !CNT[i]) {
		for(int j : G[i]) {
			if(DP[i].se == DP[j].se && DP[i].fi == DP[j].fi + 1)
				CNT[i]++;
		}
	}

	
	for(int i = 1; i <= N; i++) if(i == uf(i)) {
		if(i != RA) {
			bool flag = false;
			for(int v : T[i])
				flag |= D[RA][v] + 1 == D[RA][i];

			if(!flag) return 0;
		}
		if(i != RB) {
			bool flag = false;
			for(int v : T[i])
				flag |= D[RB][v] + 1 == D[RB][i];
			if(!flag) return 0;
		}
	}


	ll ret = 1;
	for(int i = 1; i <= N; i++) if(i == uf(i))
		ret = ret * CNT[i] % MOD;
	
	return ret;
}


bitset<405> Achk, Bchk;
int solve2(int RA, int RB) {
	Achk.reset(); Bchk.reset();

	for(int i = 1; i <= N; i++) if(i == uf(i)) {
		int da = D[RA][i];
		int db = D[RB][i];

		if(da == db) return 0;

		(da < db ? Achk : Bchk)[i] = true;
	}

	ll ret = 1;

	for(int i = 1; i <= N; i++) if(i == uf(i) && i != RA && i != RB) {
		int cnt = 0;

		if(Achk[i]) {
			for(int v : G[i])
				if(Achk[v] && D[RA][v] + 1 == D[RA][i])
					cnt++;
		} else {
			for(int v : G[i])
				if(Bchk[v] && D[RB][v] + 1 == D[RB][i])
					cnt++;
		}

		ret = ret * cnt % MOD;
	}

	return ret;
}


void dfs(int i, int p, int &c) {
	dfo[i] = ++c;
	dup[i] = dfo[i];

	for(int v : G[i]) if(v != p) {
		if(!dfo[v]) {
			dfs(v, i, c);

			if(dup[v] > dfo[i]) {
				uf(i, v);
			}

			upmin(dup[i], dup[v]);
		} else {
			upmin(dup[i], dfo[v]);
		}
	}
}

int solve1(int R) {
	ll ret = 1;

	for(int i = 1; i <= N; i++) if(i != R && i == uf(i)) {
		int cnt = 0;
		for(int j : G[i])
			if(D[R][j] + 1 == D[R][i])
				cnt++;

		ret = ret * cnt % MOD;
	}

	return ret;
}

void precal() {
	bitset<405> chk;

	for(int i = 1; i <= N; i++) if(i == uf(i)) {
		chk.reset();

		D[i][i] = 0;
		chk[i] = true;

		queue<int> PQ;
		PQ.emplace(i);

		for(int v, dst; !PQ.empty();) {
			v = PQ.front(); PQ.pop();
			dst = D[i][v] + 1;

			for(int u : G[v]) if(!chk[u]) {
				chk[u] = true;
				D[i][u] = dst;
				PQ.emplace(u);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for(int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		fg(G, A[i], B[i]);
	}

	iota(ud, ud+N+1, 0);
	{
		int order = 0;
		dfs(1, 0, order);
	}


	for(int i = N; i; i--) G[i].clear();

	for(int i = 1, a, b; i <= M; i++) {
		a = uf(A[i]);
		b = uf(B[i]);
		if(a != b) {
			fg(G, a, b);
		}
	}

	for(int i = 1; i <= N; i++) {
		sorv(G[i]);
		univ(G[i]);
	}



	precal();




	for(int i = 1; i <= N; i++) if(i == uf(i)) Ans[i][i] = solve1(i);

	for(int i = 1, a, b; i <= M; i++) {
		a = uf(A[i]);
		b = uf(B[i]);
		if(a == b) continue;

		Ans[a][b] = Ans[b][a] = solve2(a, b);
	}

	for(int i = 1; i <= N; i++) if(i == uf(i))
		for(int j = i+1; j <= N; j++) if(j == uf(j))
			if(D[i][j] > 1)
				Ans[i][j] = Ans[j][i] = solve3(i, j);



	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++)
			cout << Ans[uf(i)][uf(j)] << ' ';
		cout << '\n';
	}

	return 0;
}
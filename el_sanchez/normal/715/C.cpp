#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
const int MAXN = 100500;

int p10[MAXN], inv[MAXN];

int gcd(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int n, M;
vector<pii> g[MAXN];
int parent[MAXN];
int level[MAXN];

int dfs(int v, int &center, int sz = 0, int p = -1) {
	int sum = 1;
	for (auto e: g[v]) {
		int w = e.X;
		if (w != p && level[w] == -1)
			sum += dfs(w, center, sz, v);	
	}
	if (center == -1 && 2 * sum >= sz)
		center = v;	
	return sum;
}

void build(int v, int L = 0, int p = -1) {
	int center;
	dfs(v, center = -1, dfs(v, center));

	parent[center] = p;
	level[center] = L;

	for (auto e: g[center]) {
		int w = e.X;
		if (level[w] == -1)
			build(w, L + 1, center);		
	}
}

ll ans;

int up[MAXN], down[MAXN];

void dfs2(int v, int L, int p = -1, int h = 0) {
	for (auto e: g[v]) {
		int w = e.X;
		int d = e.Y;
		if (w != p && level[w] >= L) {
			up[w] = (1ll * d * p10[h] + up[v]) % M;
			down[w] = (1ll * down[v] * 10 + d) % M;
			
			//cout << "dfs(" << w << "):\n";
			//cout << up[w] << ' ' << down[w] << '\n';
			
			dfs2(w, L, v, h + 1);		
		}
	}		
}

vi childs;
map<int, int> ptails[MAXN];
map<int, int> tails;
int ID;

void dfs3(int v, int L, int p, int h) {
	int y = 1ll * down[v] * inv[h] % M;
	ptails[ID][y]++;
	tails[y]++;
	
	for (auto e: g[v]) {
		int w = e.X;
		if (w != p && level[w] >= L) {
			dfs3(w, L, v, h + 1);		
		}
	}		
}

void dfs4(int v, int L, int p = -1) {
	int need = (M - up[v]) % M;
	//cout << v << ' ' << need << '\n';
	if (tails.find(need) != tails.end())
		ans += tails[need];
	if (ptails[ID].find(need) != ptails[ID].end())
		ans -= ptails[ID][need];
	
	for (auto e: g[v]) {
		int w = e.X;
		if (w != p && level[w] >= L) {
			dfs4(w, L, v);		
		}
	}		
}

void getAns(int c, int L) {
	up[c] = 0;
	down[c] = 0;
	dfs2(c, L);
	
	childs.clear();
	for (auto e: g[c]) {
		int w = e.X;
		if (level[w] >= L)
			childs.pb(w);
	}
	
	tails.clear();
	forn(i, childs.size())
		ptails[i].clear();
	tails[0]++;
	
	forn(i, childs.size()) {
		ID = i;
		dfs3(childs[i], L, c, 1);			
	}
	/*
	cout << "CENTER " << c << ":\n";
	for (auto p: tails)
		cout << p.X << ": " << p.Y << '\n';
	*/	

	//calc
	forn(i, childs.size()) {
		ID = i;
		dfs4(childs[i], L, c);			
	}
	
	if (tails.find(0) != tails.end())
		ans += tails[0] - 1;
}

int main() {
	
	cin >> n >> M;
	
	if (M == 1) {
		cout << 1ll * n * (n - 1) << '\n';
		return 0;	
	}
	
	int i10, y;
	int gg = gcd(10, M, i10, y);
	assert(gg == 1);
	i10 %= M;
	i10 = (M + i10) % M;
	//cout << M << '\n';
	//cout << 1ll * i10 * 10 % M << '\n';
	assert(1ll * i10 * 10 % M == 1);
	
	inv[0] = 1;
	forab(i, 1, MAXN)
		inv[i] = (1ll * inv[i - 1] * i10) % M;
	p10[0] = 1;
	forab(i, 1, MAXN)
		p10[i] = (1ll * p10[i - 1] * 10) % M;
			
	forn(i, n - 1) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		g[a].pb({b, d});
		g[b].pb({a, d});
	}

	memset(level, -1, sizeof(level));
	build(0);
	/*
	forn(i, n)
		cout << i << ' ' << level[i] << '\n';
	*/	
	ans = 0;
	forn(c, n) {
		getAns(c, level[c]);	
		//cout << ans << '\n';
	}
	
	cout << ans << '\n';
	
	return 0;
}
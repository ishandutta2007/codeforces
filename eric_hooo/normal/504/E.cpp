#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

void read(int &x) {
	char c = getchar(); while (c < '0' || c > '9') c = getchar();
	x = c - '0', c = getchar(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

const int mod1 = 998244353;
const int mod2 = 1000000007;
const int P1 = 323232323;
const int P2 = 2333;

int Add(int x, int y, int mod) {return x + y >= mod ? x + y - mod : x + y;}

int Sub(int x, int y, int mod) {return x - y < 0 ? x - y + mod : x - y;}

struct Num {
	int x1, x2;
	Num() {x1 = 0;}
	Num(int x) {x1 = x;}
	// Num(int x, int y) {x1 = x, x2 = y;}
	Num operator * (const Num &A) const {return Num(1ll * x1 * A.x1 % mod1);}
	Num operator + (const Num &A) const {return Num(Add(x1, A.x1, mod1));}
	Num operator - (const Num &A) const {return Num(Sub(x1, A.x1, mod1));}
	bool operator == (const Num &A) const {return x1 == A.x1;}
};

namespace StrHash {
	char *s;
	int n;
	Num H[600010], pw[600010];
	void init(char *t, int N) {
		s = t, n = N;
		pw[0] = 1, pw[1] = Num(P1); for (int i = 2; i <= n; i++) pw[i] = pw[i - 1] * pw[1];
		for (int i = 1; i <= n; i++) {
			H[i] = H[i - 1] * pw[1] + Num(t[i]);
		}
	}
	Num GetHash(int l, int r) {
		return H[r] - H[l - 1] * pw[r - l + 1];
	}
}

using StrHash :: GetHash;

int n;
char s[300010];
vector <int> G[300010];
int fa[300010], dep[300010], sz[300010], son[300010], tp[300010], dfn[300010], num[300010], DFN;
char t[600010];

void dfs1(int x, int last) {
	fa[x] = last, sz[x] = 1, son[x] = 0;
	for (auto v : G[x]) if (v != last) {
		dep[v] = dep[x] + 1, dfs1(v, x), sz[x] += sz[v];
		if (!son[x] || sz[v] > sz[son[x]]) son[x] = v;
	}
}

void dfs2(int x, int t) {
	tp[x] = t, dfn[x] = ++DFN, num[DFN] = x;
	if (!son[x]) return ;
	dfs2(son[x], t);
	for (auto v : G[x]) if (v != fa[x] && v != son[x]) {
		dfs2(v, v);
	}
}

vector <pii> P, Q;
vector <pii> chain[2];

pii Reverse(pii x) {
	return mp(n + n - x.se + 1, n + n - x.fi + 1);
}

int Len(pii x) {
	return x.se - x.fi + 1;
}

void GetRng(int x, int y, vector <pii> &a) {
	int flag = 0;
	chain[0].clear(), chain[1].clear();
	while (tp[x] != tp[y]) {
		if (dep[tp[x]] < dep[tp[y]]) swap(x, y), flag ^= 1;
		chain[flag].push_back(mp(dfn[tp[x]], dfn[x])), x = fa[tp[x]];
	}
	if (flag) swap(x, y);
	if (dfn[x] < dfn[y]) chain[1].push_back(mp(dfn[x], dfn[y]));
	else chain[0].push_back(mp(dfn[y], dfn[x]));
	a.clear();
	for (auto it : chain[0]) {
		a.push_back(Reverse(it));
	}
	reverse(chain[1].begin(), chain[1].end());
	for (auto it : chain[1]) {
		a.push_back(it);
	}
}

int GetLcp() {
	// cerr << "   P:"; for (auto it : P) cerr << "  " << it.fi << " " << it.se; cerr << endl;
	// cerr << "   Q:"; for (auto it : Q) cerr << "  " << it.fi << " " << it.se; cerr << endl;
	int p = 0, q = 0, pp = 0, qq = 0, lcp = 0;
	while (p < P.size() && q < Q.size()) {
		int tmp = min(Len(P[p]) - pp, Len(Q[q]) - qq);
		if (GetHash(P[p].fi + pp, P[p].fi + pp + tmp - 1) == GetHash(Q[q].fi + qq, Q[q].fi + qq + tmp - 1)) {
			pp += tmp, qq += tmp, lcp += tmp;
			if (pp == Len(P[p])) p++, pp = 0;
			if (qq == Len(Q[q])) q++, qq = 0;
		} else {
			int l = 0, r = tmp - 1;
			while (l < r) {
				int mid = l + r + 1 >> 1;
				if (GetHash(P[p].fi + pp, P[p].fi + pp + mid - 1) == GetHash(Q[q].fi + qq, Q[q].fi + qq + mid - 1)) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			return lcp + l;
		}
	}
	return lcp;
}

int main() {
	// freopen("string.in", "r", stdin);
	// freopen("string.out", "w", stdout);
	read(n);
	scanf("%s", s + 1);
	for (int i = 1; i < n; i++) {
		int x, y; read(x), read(y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	{ // PreCalc
		dfs1(1, 1), dfs2(1, 1);
		for (int i = 1; i <= n; i++) {
			t[i] = s[num[i]];
			t[n + n - i + 1] = s[num[i]];
		}
		StrHash :: init(t, n + n);
	}
	{ // Process Query
		int q; scanf("%d", &q);
		while (q--) {
			int a, b, c, d; read(a), read(b), read(c), read(d);
			GetRng(a, b, P), GetRng(c, d, Q);
			printf("%d\n", GetLcp());
		}
	}
	return 0;
}
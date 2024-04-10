#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
const int K = 93;
const int N = 4e5 + 100;
const int MOD = 998244353;
 
int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}
 
int rev(int x) {
	if (!x) return 0;
	return MOD - x;
}
 
int mult(int a, int b) {
	return int((a * 1ll * b) % MOD);
}
 
int toPow(int x, int d) {
	if (d == 0) return 1;
	int t = toPow(x, d / 2);
	t = mult(t, t);
	if (d & 1) t = mult(t, x);
	return t;
}
 
int toInv(int x) {
	return toPow(x, MOD - 2);
}
 
int n;
int inv[N], res[N], total[N], invTotal[N], tin[N], tout[N], curT;
int localV[2 * N];
vector<int> g[N];
 
bool isParent(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}
 
set<pii> childrenSizes[N];
vector<pair<pii, int>> childrenChar[N];
 
void dfs(int v, int p) {
	tin[v] = curT++;
	total[v] = 1;
	for(int to : g[v]) {
		if (to == p) continue;
		dfs(to, v);
		total[v] += total[to];
		childrenSizes[v].insert(mp(tout[to], mult(n - total[to], inv[n])));
		childrenChar[v].pb(mp(mp(tin[to], tout[to]), mult(n - total[to], inv[n])));
	}
	invTotal[v] = mult(total[v], inv[n]);
	tout[v] = curT++;
	localV[tin[v]] = v;
}
 
int toAdd[2 * N], addition[2 * N];
 
void addSeg(int a, int b, int x) {
//	cerr << "ADD SEG " << a << " " << b << " " << x << '\n';
	toAdd[a] = add(toAdd[a], x);
	toAdd[b] = add(toAdd[b], rev(x));
}
 
void updateAll(vector<pii> &modify) {
	forn(i, n) {
		addition[i] = 0;
	}
	forn(i, curT + 1) {
		toAdd[i] = 0;
	}
	for(pii p : modify) {
		addition[p.fst] = add(addition[p.fst], p.snd);
	}
	forn(i, n) {
		if (addition[i]) {
		//	cerr << "ADD " << i << '\n';
			for(auto p : childrenChar[i]) {
				int toIn = p.fst.fst;
				int toOut = p.fst.snd;
				int x = mult(p.snd, addition[i]);
				addSeg(toIn, toOut + 1, x);
			}
			addSeg(tin[i], tin[i] + 1, addition[i]);
			int x = mult(addition[i], invTotal[i]);
			if (tin[i]) addSeg(0, tin[i], x);
			if (tout[i] + 1 < curT) addSeg(tout[i] + 1, curT, x);
		}
	}
	int last = 0;
	forn(i, curT) {
//		cerr << last << " " << toAdd[i] << '\n';
		last = add(last, toAdd[i]);
		if (localV[i] != -1) {
			int v = localV[i];
//			cerr << "AT TIME " << i << " IN " << v << " " << last << '\n';
			res[v] = add(res[v], last);
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	forab(i, 1, N) {
		inv[i] = toInv(i);
	}
	forn(i, 2 * N) {
		localV[i] = -1;
	}
//	cerr << "!\n";
	int q;
	cin >> n >> q;
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
//	cerr << "!\n";
	dfs(0, 0);
//	cerr << "!\n";
	vector<pii> modify;
	forn(i, q) {
	//	cerr << i << '\n';
		int t;
		cin >> t;
		if (t == 1) {
			int v, d;
			cin >> v >> d;
			v--;
			modify.pb(mp(v, d));
			if (sz(modify) % K == 0) {
				updateAll(modify);
				modify.clear();
			}
		} else {
			int v;
			cin >> v;
			v--;
			int ans = res[v];
			for(pii m : modify) {
				int u = m.fst;
				int d = m.snd;
				if (u == v) {
					ans = add(ans, d);
				} else if (isParent(u, v)) {
					auto p = childrenSizes[u].lower_bound(mp(tout[v], -1));
					ans = add(ans, mult(p->snd, d));
				} else {
					int invSize = invTotal[u];
					ans = add(ans, mult(invSize, d));
				}
			}
			cout << ans << '\n';
		}
	}
	
    return 0;
}
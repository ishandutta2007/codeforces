#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 205;
const int MOD = 1e9 + 7;

int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}

int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + MOD : a;
}

int mult(int a, int b) {
	return int((a * 1ll * b) % MOD);
}

int power(int x, int d) {
	if (d == 0) return 1;
	int t = power(x, d / 2);
	t = mult(t, t);
	if (d & 1) t = mult(t, x);
	return t;
}

int inv(int x) {
	return power(x, MOD - 2);
}

vi g[N];
int subSize[N];

void initDfs(int v, int p) {
	subSize[v] = 1;
	for(int to : g[v]) {
		if (to != p) {
			initDfs(to, v);
			subSize[v] += subSize[to];
		}
	}
}

int ans = 0, pWin[N][N];
vector<int> path;
int initV, nInv, inv2;

void updateAns() {
	forn(i, sz(path)) {
//		cerr << path[i] << " -- path\n";
		ans = add(ans, mult(path[i], pWin[i][sz(path) - i - 1]));
//		cerr << "win " << pWin[i][sz(path) - i] << '\n';
	}
//	cerr << '\n';
//	cerr << "ANS = " << ans << '\n';
}

void finitoDfs(int v, int p) {
	if (v < initV) {
//		cerr << "RUNNING FOR " << initV << " " << v << '\n';
		int pV = mult(subSize[v], nInv);
		path.pb(pV);
		updateAns();
		path.pop_back();
	}
	for(int to : g[v]) {
		if (to != p) {
			int val = mult(subSize[v] - subSize[to], nInv);
			path.pb(val);
			finitoDfs(to, v);
			path.pop_back();
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	inv2 = inv(2);
	forn(i, N) {
		pWin[0][i] = 1;
		pWin[i][0] = 0;
	}
	forab(i, 1, N) {
		forab(j, 1, N) {
			pWin[i][j] = add(mult(pWin[i - 1][j], inv2), mult(pWin[i][j - 1], inv2));
		}
	}
/*	forn(i, 10) {
		forn(j, 10) {
			cerr << pWin[i][j] << " ";
		}
		cerr << '\n';
	}*/
	int n;
	cin >> n;
	nInv = inv(n);
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	forn(v, n) {
		initDfs(v, v);
		initV = v;
		finitoDfs(v, v);
	}
	cout << ans << '\n';
	return 0;
}
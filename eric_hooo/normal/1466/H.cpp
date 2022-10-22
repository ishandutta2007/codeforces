#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mod = 1000000007;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;

int n;
map <vector <int>, int> ID;
vector <ppi> sub[300000];
vector <int> mem[300000];
int minj[300000], nxt[300000];
int EPT;
int dp[2022][2022], add[2022][2022];
int coef[50][2022];
int C[50][50], fac[50];

void PreCalcSub() {
	int maxj = 0;
	vector <int> Maxj;
	for (int i = 0; i < ID.size(); i++) {
		// if (i % 1 == 0) cerr << " i:" << i << endl;
		vector <ppi> &sub = :: sub[i];
		vector <int> &a = :: mem[i];
		vector <int> p, q;
		auto dfs = [&](int now, int coef, auto dfs) -> void {
			if (now == a.size()) {
				sub.push_back(mp(mp(ID[p], ID[q]), coef));
				return ;
			}
			int nxt = now; while (nxt < a.size() && a[now] == a[nxt]) p.push_back(a[now]), nxt++;
			dfs(nxt, 1ll * coef * C[nxt - now][0], dfs);
			for (int i = now; i < nxt; i++) {
				q.push_back(p.back()), p.pop_back();
				dfs(nxt, 1ll * coef * C[nxt - now][i - now + 1] % mod, dfs);
			}
			for (int i = now; i < nxt; i++) {
				q.pop_back();
			}
		};
		dfs(0, 1, dfs);
		// cerr << "              I:" << i << " " << sub.size() << endl;
		if (maxj < (int)sub.size()) maxj = sub.size(), Maxj = a;
		maxj = max(maxj, (int)sub.size());
	}
	// cerr << "        maxj:" << maxj << endl;
	// cerr << "                Maxj:"; for (auto it : Maxj) cerr << " " << it; cerr << endl;
}

void PreCalcAll() {
	vector <int> a;
	auto dfs = [&](int n, int k, auto dfs) -> void {
		if (n == 0) {
			int tmp = ID.size();
			ID[a] = tmp, mem[tmp] = a;
			return ;
		}
		if (n < k) return ;
		dfs(n, k + 1, dfs);
		a.push_back(k);
		dfs(n - k, k, dfs);
		a.pop_back();
	};
	for (int i = 1; i <= 40; i++) {
		dfs(i, 1, dfs);
	}
}

void PreCalcOne(vector <int> a) {
	vector <int> p;
	auto dfs = [&](int now, auto dfs) -> void {
		if (now == a.size()) {
			assert(!ID.count(p));
			int tmp = ID.size();
			ID[p] = tmp, mem[tmp] = p;
			return ;
		}
		int nxt = now; while (nxt < a.size() && a[nxt] == a[now]) nxt++;
		dfs(nxt, dfs);
		for (int i = now; i < nxt; i++) {
			p.push_back(a[now]);
			dfs(nxt, dfs);
		}
		for (int i = now; i < nxt; i++) {
			p.pop_back();
		}
	};
	dfs(0, dfs);
	EPT = ID[{}];
}

int main() {
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	for (int i = 0; i <= 44; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			ADD(C[i][j] = C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	fac[0] = 1; for (int i = 1; i <= 44; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	cin >> n;
	vector <int> A;
	{
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i], a[i]--;
		}
		vector <int> vis(n, 0);
		vector <int> tmp;
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			int cnt = 0;
			int x = i; while (!vis[x]) vis[x] = 1, x = a[x], cnt++;
			tmp.push_back(cnt);
		}
		sort(tmp.begin(), tmp.end());
		A = tmp;
	}
	// A = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 6}, n = 40;
	PreCalcOne(A);
	PreCalcSub();
	auto PreCalcOth = [&]() -> void {
		for (int i = 0; i < ID.size(); i++) {
			vector <int> a = :: mem[i];
			if (!a.size()) continue;
			minj[i] = a[0], a.erase(a.begin()), nxt[i] = ID[a];
		}
		for (int i = 0; i < ID.size(); i++) {
			for (auto it : sub[i]) {
				add[it.fi.fi][it.fi.se] = i;
			}
		}
		vector <pii> ord;
		for (int i = 0; i < ID.size(); i++) {
			int nd = 0;
			for (auto it : mem[i]) {
				nd += it;
			}
			ord.push_back(mp(nd, i));
			if (nd == n) continue;
			for (int j = 0; j <= nd; j++) {
				ADD(coef[1][i], 1ll * C[nd][j] * fac[j] % mod * fac[n - 1 - j] % mod);
			}
			for (int j = 2; j <= n; j++) {
				coef[j][i] = 1ll * coef[j - 1][i] * coef[1][i] % mod;
			}
		}
		sort(ord.begin(), ord.end());
		for (auto it : ord) {
			int x = it.se;
			for (int j = 0; j <= n; j++) {
				for (auto jt : sub[x]) {
					if (jt.fi.fi != x) SUB(coef[j][x], 1ll * coef[j][jt.fi.fi] * jt.se % mod);
				}
			}
		}
	};
	PreCalcOth();
	// return 0;
	int beg = ID[A];
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	auto GetDp = [&](int x, int y, auto GetDp) -> int {
		if (x == EPT) return y == EPT;
		if (~dp[x][y]) return dp[x][y];
		int &res = dp[x][y] = 0;
		for (auto it : sub[y]) {
			for (auto jt : sub[it.fi.se]) {
				ADD(res, 1ll * it.se * jt.se % mod * coef[minj[x]][it.fi.se] % mod * GetDp(add[nxt[x]][jt.fi.se], add[it.fi.fi][jt.fi.fi], GetDp) % mod);
			}
		}
		return res;
	};
	for (auto it : sub[beg]) {
		if (it.fi.fi != EPT) ADD(ans, 1ll * GetDp(it.fi.fi, it.fi.se, GetDp) * it.se % mod);
	}
	cout << ans << endl;
	return 0;
}
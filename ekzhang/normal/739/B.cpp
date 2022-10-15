#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 200013
#define INF (1LL<<50);
#define MAXLG 20
int N;
LL A[MAXN];
int parent[MAXN];
LL weight[MAXN];
vector<int> ch[MAXN];
int depth[MAXN];
LL toroot[MAXN];
int L[MAXN][MAXLG];
int pref[MAXN];
int ans[MAXN];

void dfs(int n) {
	if (n) {
		depth[n] = depth[parent[n]] + 1;
		toroot[n] = toroot[parent[n]] + weight[n];
	}
	for (int x : ch[n]) {
		dfs(x);
	}
}

void lcadp_init() {
	for (int i = 0; i < N; i++) {
		L[i][0] = parent[i];
	}
	for (int lg = 0; lg < MAXLG - 1; lg++) {
		for (int i = 0; i < N; i++) {
			L[i][lg+1] = L[L[i][lg]][lg];
		}
	}
}

int ancestor(int n, int k) {
	// k-th ancestor of n
	if (k >= depth[n]) {
		return 0;
	}
	int ret = n;
	for (int lg = MAXLG - 1; lg >= 0; lg--) {
		if ((1<<lg) <= k) {
			k -= (1<<lg);
			ret = L[ret][lg];
		}
	}
	return ret;
}

int where(int n) {
	// remember: weight[n] >= toroot[n] - toroot[v];
	int lo = 0;
	int hi = depth[n];
	while (lo != hi) {
		int mid = (lo + hi + 1) / 2;
		int x = ancestor(n, mid);
		if (A[n] >= toroot[n] - toroot[x]) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return ancestor(n, lo);
}

void dfs2(int n) {
	ans[n] = pref[n];
	for (int x : ch[n]) {
		dfs2(x);
		ans[n] += ans[x];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	parent[0] = 0;
	weight[0] = INF;
	for (int i = 1; i < N; i++) {
		cin >> parent[i] >> weight[i];
		parent[i]--;
		ch[parent[i]].push_back(i);
	}

	dfs(0);
	lcadp_init();

	for (int u = 1; u < N; u++) {
		int v = where(u);
		// error(u, v);
		pref[parent[u]] += 1;
		if (v) {
			pref[parent[v]] -= 1;
		}
	}

	dfs2(0);

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}
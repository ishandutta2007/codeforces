#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <unordered_set>

using namespace std;

const long long mod = 1e16 + 229;
const int base = 139;

const int N = 1e6 + 228;

int timer = 1;
int go[N][26];
vector<int> who[N];
vector<int> G[N];

void solve() {
	int n;
	cin >> n;
	unordered_set<long long> used(30 * n);
	vector<vector<int>> can(n);
	vector<string> b(n);
	timer = 1;
	fill(go[0], go[0] + 26, -1);
	int z = 0;
	vector<int> deg(n, -1);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		b[i] = s;
		int k = s.size();
		can[i].resize(k);
		long long hash = 1;
		for (int j = 0; j < k; ++j) {
			hash = (hash * base + (s[j] - 'a')) % mod;
			if (used.count(hash)) {
				continue;
			} else {
				can[i][j] = 1;
				used.insert(hash);
			}
		}
		int now = 0;
		for (int j = 1; j < k; ++j) {
			if (go[now][s[j] - 'a'] == -1) {
				go[now][s[j] - 'a'] = timer;
				fill(go[timer], go[timer] + 26, -1);
				who[timer].clear();
				timer++;
			}
			now = go[now][s[j] - 'a'];
			if (can[i][j]) {
				if ((int) deg.size() <= z + j)
					deg.resize(z + j + 2, -1);
				deg[z + j] = 0;
				who[now].push_back(z + j);
			}
		}
		for (int j = 0; j < k; ++j) {
			if (can[i][j]) {
				if ((int) deg.size() <= z + j)
					deg.resize(z + j + 2, -1);
				deg[z + j] = 0;
			}
		}
		z += k;
	}
	for (int i = 0; i < z; ++i)
		G[i].clear();

	z = 0;
	vector<int> st;
	for (int i = 0; i < n; ++i) {
		int now = 0;
		int k = b[i].size();
		string s = b[i];
		for (int j = 0; j < k; ++j) {
			if (go[now][s[j] - 'a'] == -1)
				break;
			now = go[now][s[j] - 'a'];
			if (can[i][j]) {
				for (auto p : who[now]) {
					G[z + j].push_back(p);
					G[p].push_back(z + j);
					++deg[p], ++deg[z + j];
				}
			}
		}
		z += k;
	}
	int ans = 0;
	vector<int> ban1(z), ban2(z), ban3(z);
	deg.resize(z + 1, -1);
	for (int i = 0; i < z; ++i) {
		if (deg[i] < 2 && deg[i] != -1) {
			ban2[i] = 1;
			st.push_back(i);
		}
	}
	while (st.size()) {
		int v = st.back();
		st.pop_back();
		ban3[v] = 1;
		if (ban1[v])
			continue;
		++ans;
		// cout << v << ":\n";
		for (int i : G[v]) {
			// cout << '!' << i << '\n';
			if (!ban1[i] && !ban3[i]) {
				ban1[i] = 1;
				for (int j : G[i]) {
					if (!ban1[j] && !ban2[j]) {
						--deg[j];
						if (deg[j] < 2) {
							st.push_back(j);
							ban2[j] = 1;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif


	int t;
	cin >> t;
	while (t--)
		solve();
}
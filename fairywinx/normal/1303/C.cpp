#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>
#include <queue>

#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif
}

void ct(vector<int> &a) {
	for(auto i: a)
		cout << i << ' ';
	cout << '\n';
}

void ct(pair<int, int> &a) {
	cout << a.first << ':' << a.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		ct(i);
}

void ci(vector<int> &a) {
	for(auto &i: a)
		cin >> i;
}

void ci(vector<pair<int, int>> &a) {
	for(auto &i: a)
		cin >> i.first >> i.second;
}

const int N = 30;
set<int> g[N];

bool dfs(int v, vector<int> &used, string &ans) {
	used[v] = 1;
	ans += (v + 'a');
	int k = 0;
	for(auto i: g[v]) {
		if (!used[i])
			++k;
	}
	// cout << v + 'a' << ' ' << k << '\n';
	if (k > 1)
		return false;
	if (k == 0)
		return true;
	for(auto i: g[v]) {
		if (!used[i])
			return dfs(i, used, ans);
	}
}

void solve() {
	for(int i = 0; i < N; ++i) 
		g[i].clear();

	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n - 1; ++i) {
		int z = s[i] - 'a';
		int v = s[i + 1] - 'a';
		g[z].insert(v);
		g[v].insert(z);
	}
	if (n == 1) {
		cout << "YES\n";
		for(int i = 0; i < 26; ++i) {
			cout << char(i + 'a');
		}
		cout << '\n';
		return;
	}
	// for(int i = 0; i < 26; ++i)
	// 	ct(g[i]);
	for(int i = 0; i < 26; ++i) {
		string ans = "";
		vector<int> used(26);
		if (g[i].size() == 0)
			continue;
		if (dfs(i, used, ans)) {
			cout << "YES\n";
			for(auto i: ans) 
				cout << i;
			for(int i = 0; i < 26; ++i) {
				if (!used[i])
					cout << char(i + 'a');
			}
			cout << '\n';
			return;
		}
	}
	cout << "NO\n";
}

signed main() {
	setup();
	int t; cin >> t; for(int i = 0; i < t; ++i) solve();
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}
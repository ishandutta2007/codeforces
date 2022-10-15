#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 300013
int N;
int ans[MAXN];
int G[MAXN][26];

int merge(const vector<int>& v) {
	if (v.size() <= 1) return 0;
	int diff = v.size() - 1;
	for (int ch = 0; ch < 26; ch++) {
		vector<int> v2;
		for (int n : v) {
			if (~G[n][ch]) {
				v2.push_back(G[n][ch]);
			}
		}
		diff += merge(v2);
	}
	return diff;
}

void dfs(int n, int d=0) {
	vector<int> v;
	for (int ch = 0; ch < 26; ch++) {
		if (~G[n][ch]) {
			v.push_back(G[n][ch]);
			dfs(G[n][ch], d+1);
		}
	}
	if (v.size()) {
		ans[d] += 1 + merge(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	memset(G, -1, sizeof G);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		char x;
		cin >> u >> v >> x;
		u--; v--;
		G[u][x - 'a'] = v;
	}

	dfs(0);

	int res = 0;
	for (int i = 0; i < N; i++) {
		if (ans[i] > ans[res]) {
			res = i;
		}
	}

	cout << N - ans[res] << endl << res + 1 << endl;
	return 0;
}
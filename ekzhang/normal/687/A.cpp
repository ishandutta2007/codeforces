#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

const int MAXN = 100000;

int N, M;
vector<int> adj[MAXN];
int color[MAXN];
vector<int> ans[2];

bool dfs(int n, int c, int prev) {
	if (color[n] != -1) {
		return (color[n] == c);
	}
	color[n] = c;
	ans[c].push_back(n);
	for (int x : adj[n]) {
		if (x != prev) {
			bool res = dfs(x, !c, n);
			if (!res) {
				// uh-oh
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool isok = true;

	memset(color, -1, sizeof color);
	for (int i = 0; i < N; i++) {
		if (color[i] == -1) {
			isok &= dfs(i, 0, -1);
		}
	}

	if (!isok) {
		cout << -1 << endl;
		return 0;
	}

	for (int c = 0; c < 2; c++) {
		cout << ans[c].size() << endl;
		for (int x : ans[c]) {
			cout << x + 1 << ' ';
		}
		cout << endl;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
int N, M;
vector<int> adj[MAXN];
int height[MAXN];
int ans = 0;

void dfs(int n, int prev=-1) {
	height[n] = 1;
	int a = 0, b = 0; // a >= b
	for (int x : adj[n]) {
		if (x == prev) continue;
		dfs(x, n);
		height[n] = max(height[n], height[x] + 1);

		if (height[x] > b) {
			b = height[x];
			if (b > a) {
				swap(a, b);
			}
		}
	}
	ans = max(ans, a + b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	assert(M == N - 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0);

	cout << ans << endl;
	return 0;
}
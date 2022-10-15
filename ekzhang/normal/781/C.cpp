#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013
int N, M, K;
vector<int> adj[MAXN];
vector<int> euler;
bool visited[MAXN];

void dfs(int n) {
	euler.push_back(n);
	visited[n] = true;
	for (int x : adj[n]) {
		if (visited[x]) continue;
		dfs(x);
		euler.push_back(n);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	int maxc = (2 * N + K - 1) / K;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(0);
	int idx = 0;
	for (int i = 0; i < K; i++) {
		int c = min(maxc, (int) euler.size() - idx);
		if (!c) {
			cout << "1 1\n";
		}
		else {
			cout << c;
			for (int i = 0; i < c; i++) {
				cout << ' ' << euler[idx++] + 1;
			}
			cout << '\n';
		}
	}

	cout.flush();
	return 0;
}
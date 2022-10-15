#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 200013
#define MOD 1000000007
int N;
vector<int> adj[MAXN];

int C = 0;
int cp[MAXN];
vector<int> members[MAXN];
int neighbors[MAXN];

LL ans = 1;

void dfs(int n, int p) {
	if (n != p && cp[n] != -1) return;
	cp[n] = cp[p];
	members[cp[n]].push_back(n);
	for (int x : adj[n]) {
		dfs(x, n);
	}
}

LL pow2(int n) {
	LL ret = 1;
	for (int i = 0; i < n; i++) {
		ret = (ret * 2) % MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x; x--;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}

	memset(cp, -1, sizeof cp);
	for (int i = 0; i < N; i++) {
		if (cp[i] == -1) {
			cp[i] = C++;
			dfs(i, i);
		}
		neighbors[i] = adj[i].size();
	}

	for (int c = 0; c < C; c++) {
		queue<int> frontier;
		for (int x : members[c]) {
			if (neighbors[x] == 1) {
				frontier.push(x);
			}
		}
		while (!frontier.empty()) {
			int x = frontier.front();
			frontier.pop();
			neighbors[x] = -1;
			for (int y : adj[x]) {
				if (neighbors[y] != -1) {
					neighbors[y]--;
					if (neighbors[y] == 1) {
						frontier.push(y);
					}
				}
			}
		}
		int sub = 2;
		for (int x : members[c]) {
			assert(neighbors[x] == -1 || neighbors[x] == 2);
			if (neighbors[x] == -1) {
				sub = (sub * 2) % MOD;
			}
		}
		ans *= pow2(members[c].size()) + MOD - sub;
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013

int N;
vector<int> adj[MAXN];
int dist[MAXN];
bool saw[MAXN];

void bfs(int start) {
	for (int i = 0; i < N; i++) {
		dist[i] = 1<<30;
	}
	dist[start] = 0;
	queue<int> frontier;
	frontier.push(start);
	saw[start] = true;
	while (!frontier.empty()) {
		int x = frontier.front();
		frontier.pop();
		for (int y : adj[x]) {
			if (!saw[y]) {
				saw[y] = true;
				dist[y] = dist[x] + 1;
				frontier.push(y);
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		a--;
		if (a != i && a != i - 1 && a != i + 1) {
			adj[i].push_back(a);
		}
	}
	for (int i = 0; i < N - 1; i++) {
		adj[i].push_back(i + 1);
		adj[i + 1].push_back(i);
	}

	bfs(0);

	for (int i = 0; i < N; i++) {
		cout << dist[i] << ' ';
	}

	cout << endl;
	return 0;
}
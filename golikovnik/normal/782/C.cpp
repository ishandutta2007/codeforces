#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define endl '\n'
#define make_unique(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

const int MAXN = 222222;
vector<int> graph[MAXN];
int color[MAXN];
bool used[MAXN];

void dfs(int v, int pc = 1) {
	used[v] = 1;
	int new_c = 1;
	for (int x: graph[v]) {
		if (!used[x]) {
			while (new_c == color[v] or new_c == pc) ++new_c;
			color[x] = new_c++;
			dfs(x, color[v]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read();
	for (int i = 0; i < n - 1; ++i) {
		int x = read() - 1, y = read() - 1;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	color[0] = 1;
	dfs(0);
	cout << *max_element(color, color + n) << endl;
	for (int i = 0; i < n; ++i) {
		cout << color[i] << " ";
	}
	cout << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector <int> a;
vector <vector <bool>> g;
vector <vector <int>> ans;

int main() {
	cin >> n >> m;
	g.resize(7);
	ans.resize(7);
	for (int i = 0; i < 7; i++) g[i].resize(7);
	for (int i = 0; i < 7; i++) ans[i].resize(7);
	a.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u - 1][v - 1] = true;
		g[v - 1][u - 1] = true;
		a[u - 1]++;
		a[v - 1]++;
	}
	sort(a.begin(), a.end());
	if (n < 7) cout << m;
	if (n == 7) {
		int answer = 10;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				for (int z = 0; z < 7; z++) {
					if (i != j && i != z && j != z && g[i][z] && g[j][z]) ans[i][j]++;
				}
			}
		}
		for (int i = 0; i < 7; i++) for (int j = 0; j < 7; j++) if (i != j) answer = min(answer, ans[i][j]);
		cout << m - answer;
	}
	return 0;
}
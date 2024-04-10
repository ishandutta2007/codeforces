#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
bool tf = true;
vector <string> a;
vector <bool> used(26);
vector <int> usedsecond(26);
vector <int> ans;
vector <vector <int>> g(26);

void dfs(int v) {
	used[v] = true;
	usedsecond[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		if (usedsecond[g[v][i]] == 1)
			tf = false;
		if (!used[g[v][i]])
			dfs(g[v][i]);
	}
	ans.push_back(v);
	usedsecond[v] = 2;
}

void topological_sort() {
	for (int i = 0; i < 26; i++) 
		if (!used[i]) {
			usedsecond.resize(0);
			usedsecond.resize(26);
			dfs(i);
		}
	reverse(ans.begin(), ans.end());
}

int main() {
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < min(a[i].size(), a[i + 1].size()); j++) {
			if (a[i][j] == a[i + 1][j] && j == a[i + 1].size() - 1 && a[i + 1].size() < a[i].size())
				tf = false;
			if (a[i][j] != a[i + 1][j]) {
				g[a[i][j] - 'a'].push_back(a[i + 1][j] - 'a');
				break;
			}
		}
	topological_sort();
	if (!tf)
		cout << "Impossible";
	else {
		for (int i = 0; i < ans.size(); i++)
			cout << (char)(ans[i] + 'a');
	}
	return 0;
}
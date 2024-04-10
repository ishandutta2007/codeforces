#include <iostream>
#include <vector>

using namespace std;

int n, m, a, prev, k, used[111], ans, l;
vector<int> v[111], v2[111];

void dfs(int n) {
	used[n]=1;
	for (int i=0; i<v[n].size(); i++) if (!used[v[n][i]]) dfs(v[n][i]);
}

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> k;
		prev=-1;
		if (k) l=i+1;
		for (int j=0; j<k; j++) {
			cin >> a;
			v2[a-1].push_back(i);
		}
	}
	for (int i=0; i<m; i++) for (int j=1; j<v2[i].size(); j++) v[v2[i][j]].push_back(v2[i][j-1]), v[v2[i][j-1]].push_back(v2[i][j]);
	if (!l) cout << n;
	else {
		dfs(l-1);
		for (int i=0; i<n; i++) if (!used[i]) {
			ans++; dfs(i);
		}
		cout << ans;
	}
	return 0;
}
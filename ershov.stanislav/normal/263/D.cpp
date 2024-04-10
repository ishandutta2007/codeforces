#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[111111];
vector<int> path;
int n, m, k, a, b, used[111111], t, mint=1<<30, mini;
void dfs(int a) {
	used[a]=++t;
	path.push_back(a);
	bool d=0;
	for (int i=0; i<v[a].size(); i++) if (!used[v[a][i]]) {
		dfs(v[a][i]), d=1;
		break;
	}
	if (!d) {
		for (int i=0; i<v[a].size(); i++) mint=min(used[v[a][i]], mint);
		while (used[path[mini]]!=mint) mini++;
	}
}
int main(){
	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0);
	cout << path.size() - mini << endl;
	for (int i = mini; i<path.size(); i++) cout << path[i]+1 << ' ';
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v[333333];
int n, m, clr[333333];

int main() {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	for (int i=0; i<n; i++) q.push(i);
	while(!q.empty()) {
		int i=q.front(); q.pop();
		int b=0;
		for (int j=0; j<(int)v[i].size(); j++) if (clr[v[i][j]]==clr[i]) b++;
		if (b>1) {
			clr[i]^=1;
			for (int j=0; j<(int)v[i].size(); j++) q.push(v[i][j]);
		}
	}
	for (int i=0; i<n; i++) cout << clr[i];
	return 0;
}
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n);
		vector<int> deg(n);
		vector<pair<int, int>> edges;
		while (m--) {
			int type, a, b;
			cin >> type >> a >> b;
			--a;--b;
			edges.emplace_back(a, b);
			if (type) {
				g[a].push_back(b);
				++deg[b];
			}
		}
		queue<int> top;
		for (int i = 0; i < n; ++i) if (deg[i] == 0) top.push(i);
		int next = 0;
		vector<int> ord(n);
		while(!top.empty()) {
			int nd = top.front();
			top.pop();
			ord[nd] = next++;
			for (auto el : g[nd]) {
				if (--deg[el] == 0) top.push(el);
			}
		}
		if (next == n) {
			cout << "YES\n";
			for (auto& el : edges) {
				if (ord[el.first] > ord[el.second]) swap(el.first, el.second);
				cout << el.first + 1 << ' ' << el.second + 1 << '\n';
			}
			continue;	
		}          
		cout << "NO\n";
	}
}
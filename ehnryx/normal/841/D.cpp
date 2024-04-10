#include <bits/stdc++.h>
using namespace std;

#define debug

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
const ll MOD = 1e9+7;
const int INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

int dfs(int curr, int prev, const vector<vector<pair<int,int>>>& graph, const set<int>& bad, set<int>& ans, vector<bool>& visited) {
	if (visited[curr])
		return 0;
	visited[curr] = true;
	int pc = 0;
	if (bad.count(curr))
		pc = 1;
	for (pair<int,int> neighbour: graph[curr]) {
		if (neighbour.first == prev) continue;
		int temp = dfs(neighbour.first, curr, graph, bad, ans, visited);
		// keep even weighted edges
		//cerr << "got " << temp << " from " << neighbour.first+1 << endl;
		if (temp%2 == 0) {
			ans.insert(neighbour.second);
		}
		pc += temp;
	}
	//cerr << "visit " << curr+1 << ", return " << pc << endl;
	return pc;
}

The story of lame:

	int n, m;
	cin >> n >> m;
	set<int> bad;
	// neighbour, index
	vector<vector<pair<int,int>>> graph(n);
	int residue[n];
	int wild = -1;
	for (int i = 0; i < n; i++) {
		cin >> residue[i];
		if (residue[i] == -1)
			wild = i;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a-1].push_back(pair<int,int>(b-1, i+1));
		graph[b-1].push_back(pair<int,int>(a-1, i+1));
	}
	// count bad
	for (int i = 0; i < n; i++) {
		if (residue[i] != -1 && graph[i].size()%2 != residue[i])
			bad.insert(i);
	}
	if (bad.size()%2 == 1) {
		if (wild == -1) {
			cout << -1 << endl;
			return 0;
		}
		else {
			bad.insert(wild);
		}
	}
	//cerr << "bad: "; for(int it: bad) //cerr << it+1 << " "; //cerr << endl;
	if (bad.empty()) {
		cout << m << endl;
		for (int i = 1; i <= m; i++)
			cout << i << endl;
	}
	else {
		// dfs
		set<int> ans;
		vector<bool> visited(n);
		dfs(*bad.begin(), -1, graph, bad, ans, visited);
		cout << ans.size() << endl;
		for (int e: ans)
			cout << e << endl;
	}

The End
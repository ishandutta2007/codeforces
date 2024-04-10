#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define End return 0; }
#define lame cin.tie(0);LAME
#define of ios::sync_with_stdio(0);
#define story int main() {
#define The

struct DSU {
	vector<int> root;
	vector<int> weight;
	DSU(int n) {
		root.resize(n);
		memset(&root[0], -1, n*sizeof(root[0]));
		weight.resize(n);
		memset(&weight[0], 0, n*sizeof(weight[0]));
	}

	int find(int i) {
		if (root[i] == -1) return i;
		else return root[i] = find(root[i]);
	}
	void link(int i, int j) {
		int rooti = find(i);
		int rootj = find(j);
		if (rooti == rootj) return;
		else if (weight[rooti] > weight[rootj]) {
			root[rootj] = rooti;
			weight[rooti] += weight[rootj] + 1;
		}
		else {
			root[rooti] = rootj;
			weight[rootj] += weight[rooti] + 1;
		}
	}
};

The story of lame:

	vector<int> vec;
	int n;
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	DSU dsu(n);
	string arr;
	for (int i = 0; i < n; i++) {	
		cin >> arr;
		for (int j = i; j < n; j++)
			if (arr[j] == '1') {
				dsu.link(i,j);
			}
	}

	map<int,set<int>> groups;
	for (int i = 0; i < n; i++) {
		if (dsu.find(i) == i)
			groups.insert(pair<int,set<int>>(i, set<int>()));
	}

	for (int i = 0; i < n; i++) {
		groups[dsu.find(i)].insert(vec[i]);
	}

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = *groups[dsu.find(i)].begin();
		groups[dsu.find(i)].erase(groups[dsu.find(i)].begin());
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	} cout << endl;

The End
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define nl '\n'

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
	void link(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (weight[b] > weight[a]) swap(a,b);
		root[b] = a;
		weight[a] += weight[b]+1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a;
	vector<int> order;
	vector<int> arr;
	map<int,int> index;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		order.push_back(a);
		arr.push_back(a);
	}
	sort(order.begin(), order.end());
	for (int i = 0; i < n; i++) {
		index.insert(pii(order[i], i));
	}

	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		dsu.link(i, index[arr[i]]);
	}

	map<int,vector<int>> ans;
	for (int i = 0; i < n; i++) {
		ans[dsu.find(i)].push_back(i+1);
	}
	cout << ans.size() << nl;
	for (pair<int,vector<int>> group : ans) {
		cout << group.second.size() << " ";
		for (int it : group.second)
			cout << it << " ";
		cout << nl;
	}

	return 0;
}
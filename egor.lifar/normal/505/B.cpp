#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>


using namespace std;


#define rank rank1


int n, m;
vector<pair<int, int> > v[100000];
int parent[10000];
int rank[10000];


void make_set(int v) {
	parent[v] = v;
	rank[v] = 1;
}


int find_set(int v) {
	if (parent[v] == v) {
		return v;
	}
	parent[v] = find_set(parent[v]);
	return parent[v];
}


bool set_union(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a == b) {
		return true;
	}
	if (rank[a] >= rank[b]) {
		parent[b] = a;
		rank[a] = max(rank[a], rank[b] + 1);
	} else {
		parent[a] = b;
		rank[b] = max(rank[b], rank[a] + 1);
	}
	return false;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		a--;b--;
		v[l].push_back(make_pair(a, b));
	}
	int q;
	cin >> q;
	for (int k = 0; k < q; k++) {
		int vv, u;
		cin >> vv >> u;
		vv--;
		u--;
		int ans = 0;
		for (int j = 1; j <= m; j++) {
			for (int g = 0; g < n; g++) {
				make_set(g);
			}
			for (int g = 0; g < (int)v[j].size(); g++) {
				set_union(v[j][g].first, v[j][g].second);
			}
			if (find_set(vv) == find_set(u)) {
				ans++;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
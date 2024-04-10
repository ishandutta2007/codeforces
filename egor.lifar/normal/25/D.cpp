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


int n;
int parent[100000];
int rank[100000];
vector<pair<int, int> > v;


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
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		v.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	vector<pair<int, int> > ans;
	for (int i = 0; i < n - 1; i++) {
		int a = v[i].first;
		int b = v[i].second;
		if (set_union(a, b)) {
			ans.push_back(make_pair(a, b));
		}
	}
	cout << (int)ans.size() << endl;
	for (int i = 0; i < n; i++) {
		int g = find_set(i);
		int r = find_set(0);
		if (!set_union(r, g)) {
			cout << ans.back().first + 1 << ' ' << ans.back().second + 1 << ' ' << g + 1 << ' ' << r + 1 << endl;
			ans.pop_back();
		}
	}
    return 0;
}
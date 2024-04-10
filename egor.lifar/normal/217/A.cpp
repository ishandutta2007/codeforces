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
int x[100000];
int y[100000];
int parent[100000], rank[100000];


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
	for (int i = 0; i < n; i++) {
		make_set(i);
		cin >> x[i] >> y[i];
	}
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && (x[i] == x[j] || y[i] == y[j])) {
				set_union(i, j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!set_union(0, i)) {
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}
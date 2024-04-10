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
int a, b;
int c[100000];
int parent[100000];
int rank[100000];
int pr[100000];




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


map<int, int> m;
int v[100000];


int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		m[c[i]] = i + 1;
		make_set(i);
	}
	for (int i = 0; i < n; i++) {
		if (m[a - c[i]]) {
			set_union(find_set(i), find_set(m[a - c[i]] - 1));
			v[i] |= 1;
		}
		if (m[b - c[i]]) {
			set_union(find_set(i), find_set(m[b - c[i]] - 1));
			v[i] |= 2;
		}	
	}
	set<int> s;
	for (int j = 0; j < n; j++) {
		pr[j] = 3;
	}
	for (int j = 0; j < n; j++) {
		pr[find_set(j)] &= v[j];
	}
	for (int j = 0; j < n; j++) {
		if (pr[j] == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int j = 0; j < n; j++) {
		cout << ((pr[find_set(j)] & 1) == 0) << ' ';
	}
	cout << endl;
    return 0;
}
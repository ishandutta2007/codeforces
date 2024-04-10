#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>


using namespace std;


#define rank rank1


int n, m;
int parent[10000];
int rank[10000];
bool b[10000];


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
		make_set(i);
	}
	int ans = 0;
	int s = 0;
	int g = 0;
	for (int j = 0; j < n; j++) {
		int l;
		cin >> l;
		if (l == 0) {
			g++;
		}
		vector<int> a;
		a.resize(l);
		for (int k = 0; k < l; k++) {
			cin >> a[k];
			a[k]--;
			s = a[k];
			b[a[k]] = true;
		}
		for (int k = 0; k < l; k++) {
			for (int k1 = 0; k1 < l; k1++) {
				set_union(a[k], a[k1]);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		//cout << find_set(i) << endl;
	}
	for (int i = 0; i < m; i++) {
		if (!set_union(s, i) && b[i]) {
			ans++;
		}
	}
	cout << ans + g << endl;
    return 0;
}
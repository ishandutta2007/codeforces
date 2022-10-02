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


#define M 1000000007
#define rank rank1


int n, m;
int used[100001];
vector<int> v0[100001], v1[100001], newv[100001];


int parent[100001];
int rank[100001];


void make_set(int v) {
	parent[v] = v;
	rank[v] = 1;
}


int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	parent[v] = find_set(parent[v]);
	return parent[v];
}


bool set_union(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (rank[a] <= rank[b]) {
			parent[a] = b;
			rank[b] = max(rank[a] + 1, rank[b]);
		} else {
			parent[b] = a;
			rank[a] = max(rank[b] + 1, rank[a]);
		}
	} else {
		return true;
	}
	return false;
}



bool dfs(int u) {
	for (int j = 0; j < (int)newv[u].size(); j++) {
		int h = newv[u][j];
		if (!used[h]) {
			used[h] = 3 - used[u];
			dfs(h); 
		} else {
			if (used[h] != 3 - used[u]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c == 1) {
			v1[a - 1].push_back(b - 1);
			v1[b - 1].push_back(a - 1);
		} else {
			v0[b - 1].push_back(a - 1);
			v0[a - 1].push_back(b - 1);
		}
	}
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)v1[i].size(); j++) {
			int b = v1[i][j];
			set_union(i, b);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)v0[i].size(); j++) {
			int b = v0[i][j];
			newv[find_set(i)].push_back(find_set(b));
			newv[find_set(b)].push_back(find_set(i));
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (!used[find_set(i)]) {
			c++;
			used[find_set(i)] = 1;
			if (dfs(find_set(i))) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j  < (int)newv[i].size(); j++) {
			int a = i;
			int b = newv[i][j];
			if (used[find_set(a)] == used[find_set(b)]) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	int ans = 1;
//	cout << c << endl;
	for (int i = 0; i < c - 1; i++) {
		ans = (1LL * ans * 2LL) % M;
	}
	cout << ans << endl;
    return 0;
}
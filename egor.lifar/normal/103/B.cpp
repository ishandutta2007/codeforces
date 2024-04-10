#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>
#include <math.h>


using namespace std;


#define rank rank1


int n, m;
vector<int> v[100000];
int used[100000];
vector<int> ans;
int rank[100000];
int parent[100000];


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


int s = 0;


int dfs(int u, int g) {
	used[u] = 1;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			int t = dfs(h, u);
			if (t != -1) {
				//cout << u + 1 << endl;
				ans.push_back(u);
				if (t == u) {
					return -1;
				}
				return t;
			}
		} else {
			if (used[h] == 1 && h != g && h == s) {
			//	cout << u + 1 << endl;
				ans.push_back(u);
				return h;
			} 
		}
	}
	used[u] = 2;
	return -1;
}


void dfs1(int u) {
	used[u] = 1;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			dfs1(h);
		} 
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(used, 0, sizeof(used));
		s = i;
		dfs(i, -1);
	//	cout << i + 1 << endl;
		if (ans.size() != 0) {
			break;
		}
	}
	//cout << "opa" << endl;
	if ((int)ans.size() == 0) {
		cout << "NO" << endl;
		return 0;
	}
	memset(used, 0, sizeof(used));
	dfs1(0);
	for (int j = 0; j < n; j++) {
		if (!used[j]) {
			cout << "NO" << endl;
		return 0;
		}
	}
	///cout << "opa" << endl;
	// for (int j = 0; j < (int)ans.size(); j++) {
	// 			cout << ans[j] + 1 << ' ';
	// 		}
	// 		cout << endl;
	vector<pair<int, int> > v1;
	int g = 0;
	for (int i = 0; i < n; i++) {
		int x = i;
		for (int j = 0; j < (int)v[x].size(); j++) {
			int u = v[x][j];
			bool b = false;
			bool b1 = false;
			for (int j = 0; j < (int)ans.size(); j++) {
			//	cout << ans[j] + 1 << ' ';
				if (ans[j] == u) {
					b = true;
				//	break;
				}
				if (ans[j] == x) {
					b1 = true;
				}
			}
			if (!(b && b1) && x < u) {
				v1.push_back(make_pair(x, u));
			} else {
				if (b && b1) {
					g++;
				}
			} //else {
		//		cout << i + 1 << ' ' << u + 1 << endl;
		//	}
		} 
	}
	g /= 2;
	//cout << g << endl;
	if (g > (int)ans.size()) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	//cout << (int)ans.size() << endl;
	for (int i = 0; i < (int)v1.size(); i++) {
		int a = v1[i].first;
		int b = v1[i].second;
		if (set_union(a, b)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(find_set(i));
	}
//	cout << (int)s.size() << endl;
	//cout << (int)ans.size() << endl;
	if ((int)s.size() == (int)ans.size()) {
		cout << "FHTAGN!" << endl;
		return 0;
	}
	cout << "NO" << endl;
    return 0;
}
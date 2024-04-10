#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>



using namespace std;


#define rank rank1


int n, m, k, w;
vector<pair<int, int> > ans;
vector<pair<int, pair<int, int> > > v;
int parent[100001];
int rank[100001];
string s[1000][10];



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


bool used[100000];
vector<int> v1[100000];


void dfs(int u) {
	used[u] = true;
	for (int j = 0; j < (int)v1[u].size(); j++) {
		int h = v1[u][j];
		if (!used[h]) {
			ans.push_back(make_pair(h, u));
			dfs(h);
		}
	}
}

int main() {
	cin >> n >> m >> k >> w;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		v.push_back(make_pair(n * m, make_pair(0, i)));
	}
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			int u = 0;
			for (int g = 0; g < n; g++) {
				for (int g1 = 0; g1 < m; g1++) {
					if (s[i][g][g1] != s[j][g][g1]) {
						u++;
					}
				}
			} 
			v.push_back(make_pair(u * w, make_pair(i + 1, j + 1)));
		}
	}
	for (int j = 0; j <= k; j++) {
		make_set(j);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		if (!set_union(a, b)) {
			sum += v[i].first;
			v1[a].push_back(b);
			v1[b].push_back(a);
		}
	}
	dfs(0);
 	cout << sum << endl;
 	for (int i = 0; i < (int)ans.size(); i++) {
 		cout << ans[i].first << ' ' << ans[i].second << endl;
 	}
    return 0;
}
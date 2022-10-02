#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


#define rank rank1


int n, m;
int rank[100001];
vector<int> v[100001];
int parent[100001];
int c[100001];
vector<pair<int, int> > v1;


void make_set(int i) {
	c[i] = 1;
	rank[i] = 1;
	parent[i] = i;
}


int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	int t = find_set(parent[v]);
	parent[v] = t;
	return t;
}


bool set_union(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (rank[a] <= rank[b]) {
			parent[a] = b;
			c[b] += c[a];
			rank[b] = max(rank[a] + 1, rank[b]);
		} else {
			parent[b] = a;
			c[a] += c[b];
			rank[a] = max(rank[b] + 1, rank[a]);
		}
	} else {
		return true;
	}
	return false;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v1.push_back(make_pair(a, i));
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	long long ans = 0;
	sort(v1.begin(), v1.end());
	set<int> s;
	for (int j = n - 1; j >= 0; j--) {
		s.insert(v1[j].second);
		for (int g = 0; g < (int)v[v1[j].second].size(); g++) {
			int x = v[v1[j].second][g];
		//	cout << x + 1 << endl;
			if (s.find(x) == s.end()) {
				continue;
			}
			int a = c[find_set(v1[j].second)];
			int b = c[find_set(x)];
			if (!set_union(find_set(v1[j].second), find_set(x))) {
				ans += 1LL * v1[j].first * a * b;
			}
		}
		//cout << "opa" << ' ' << j + 1 << endl; 
	}
//	cout << ans << endl;
	printf("%.20lf\n", double(ans) / (1LL * n * (n - 1) / 2LL));
    return 0;
}
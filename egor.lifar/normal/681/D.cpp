#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


int n;
int m;
vector<int> v[100001];
int a[100001];
bool used[100001];
int cnt[100001];
vector<int> g[100001];
int deep[100001];
int in[100001];
int timer = 0;


void dfs(int u) {
	used[u] = 1;
	cnt[u] += (int)g[u].size();
	if (cnt[u] - cnt[a[u]] > 0) {
		cout << -1 << endl;
		exit(0);
	}
	timer++;
	in[u] = timer;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			cnt[h] += cnt[u];
			deep[h] = deep[u] + 1;
			dfs(h);
		}
	}
}


bool sons[100001];


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		p--;
		q--;	
		v[p].push_back(q);
		sons[q] = 1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		g[a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if ((int)g[i].size() > 1) {
			if (a[i] != i) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!sons[i]) {
			dfs(i);
		}
	}
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(in[a[i]], a[i] + 1));
	}
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	cout << (int)v.size() << endl;
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		printf("%d\n", v[i].second);
	}
    return 0;
}
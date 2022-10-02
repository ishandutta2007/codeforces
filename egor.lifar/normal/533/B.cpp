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


using namespace std;


int n;
vector<int> v[200000];
long long d[200000];
long long ans[200000][2];
bool used[200000];
long long sum = 0;


void dfs(int u) {
	used[u] = true;
	vector<int> v2;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			dfs(h);
			v2.push_back(h);
		}
	}
	vector<pair<long long, int> > v1;
	for (int j = 0; j < (int)v2.size(); j++) {
		v1.push_back(make_pair(ans[v2[j]][1] - ans[v2[j]][0], v2[j]));
		ans[u][0] += ans[v2[j]][0];
	}
	sort(v1.begin(), v1.end());
	long long s = ans[u][0];
	int t = 0;
	for (int j = (int)v1.size() - 1; j >= 0; j--) {
		s += v1[j].first;
		t++;
		t %= 2;
		ans[u][t] = max(ans[u][t], s);
	}
	ans[u][1] = max(ans[u][1], d[u] + ans[u][0]);
	sum = max(sum, ans[u][0]);
	sum = max(sum, ans[u][1]);
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, l;
		scanf("%d %d", &t, &l);
		t--;
		if (t != -2) {
			v[t].push_back(i);
		}	
		d[i] = l;
	}
	dfs(0);
	cout << sum << endl;
    return 0;
}
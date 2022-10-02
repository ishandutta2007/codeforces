#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include <cassert>


using namespace std;


int n;
vector<int> v[100001];
bool used[100001];
int ans = 0;


void dfs(int u) {
	used[u] = 1;
	int cnt = 0;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int  h = v[u][i];
		if (!used[h]) {
			cnt++;
			dfs(h);
		}
	}
	if (u != 0) {
		ans += cnt;
	}
	ans += cnt * (cnt - 1) / 2;
}


int main(){
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
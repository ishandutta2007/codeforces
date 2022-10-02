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


#define M 1000000007


int n;
vector<int> v[200000];
bool used[200000];
int up[200000], down[200000];
int ans[200000];
int parent[200000];



void dfs(int u) {
	used[u] = true;
	down[u] = 1;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			parent[h] = u;
			dfs(h);
			down[u] = (1LL * down[u] * (down[h] + 1LL)) % M;
		}
	}
}



void dfs1(int u) {
	used[u] = true;
	if (u != parent[u]) {
		up[u]++;
		up[u] %= M;
	}
	int s = 1;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (h != parent[u]) {
			up[h] = up[u];
			up[h] = (1LL * up[h] * s) % M;
					s = (1LL * s * (down[h] + 1)) % M;
		}
	}
	int s1 = 1;
	for (int i = (int)v[u].size() - 1; i >= 0; i--) {
		int h = v[u][i];
		if (h != parent[u]) {
			up[h] = (1LL * up[h] * s1) % M;
			s1 = (1LL * s1 * (down[h] + 1LL)) % M;
		}
	}
	//cout << up[u] << ' ' << u + 1 << endl;
	ans[u] = up[u];
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			dfs1(h);
			ans[u] = (1LL * ans[u] * (down[h] + 1LL)) % M;
		}
	}
}





int main(){	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a;
		scanf("%d", &a);	
		a--;
		v[a].push_back(i + 1);
		v[i + 1].push_back(a);
	}
	dfs(0);
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; i++) {
		up[i] = 1;
	}
	dfs1(0);
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	cout << endl;
	return 0;
}
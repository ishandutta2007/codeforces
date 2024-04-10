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


int n, m;
vector<int> v[100001];
bool used[100001];



void dfs(int u) {
	used[u] = 1;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int  h = v[u][i];
		if (!used[h]) {
			dfs(h);
		}
	}
}


int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cout << "no" << endl;
			return 0;
		}
	}
	if (m != n - 1) {
		cout << "no" << endl;
		return 0;
	}
	cout << "yes" << endl;
 	return 0;
}
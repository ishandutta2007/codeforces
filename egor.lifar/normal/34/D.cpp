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


int n, r1, r2;
vector<int> v[100000];
int pr[100000];
bool used[100000];


void dfs(int u) {
	used[u] = true;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int x = v[u][j];
		if (!used[x]) {
			pr[x] = u + 1;
			dfs(x);
		}
	}
}


int main() {
	cin >> n >> r1 >> r2;
	for (int j = 0; j < r1 - 1; j++) {
		int a; 
		cin >> a;
		v[a - 1].push_back(j);
		v[j].push_back(a - 1);
	}
	for (int j = r1; j < n; j++) {
		int a; 
		cin >> a;
		v[a - 1].push_back(j);
		v[j].push_back(a - 1);
	}
	dfs(r2 - 1);
	for (int j = 0; j < r2 - 1; j++) {
		cout << pr[j] << ' ';
	}
	for (int j = r2; j < n; j++) {
		cout << pr[j] << ' ';
	}
	cout << endl;
 	return 0;
}
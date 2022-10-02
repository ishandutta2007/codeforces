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
#include <tuple>
#include <unordered_set>


using namespace std;


int n;
int p[100], d[100];
vector<int> v[100];
bool used[1000];


void dfs(int u) {
	used[u] = true;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			dfs(h);
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(i - j) == d[i] || abs(i - j) == d[j]) {
				v[i].push_back(j);
			}
		}
	}	
	for (int i = 0; i < n; i++) {
		memset(used, 0, sizeof(used));
		dfs(i);
		if (!used[p[i] - 1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
    return 0;
}
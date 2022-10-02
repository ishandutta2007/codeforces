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


int n;
int deg[100000], s[100000], s1[100000];
vector<int> v[100000];


void dfs(int i) {
	int t = s[i];
	deg[i] = -1;
	v[i].push_back(t);
	if (deg[t]) {
		deg[t]--;
		s[t] ^= i;
		if (deg[t] == 1) {
			dfs(t);
		}
	}
}


int main() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> deg[i] >> s[i];
		sum += deg[i];
	}
	for (int i = 0; i < n; i++) {
		if (deg[i] == 1) {
			dfs(i);
		}
	}
	cout << sum / 2 << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			cout << i << ' ' << v[i][j] << endl;
		}
	}
    return 0;
}
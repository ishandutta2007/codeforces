#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
vector<int> v[100201];
bool deleted[1000201];
int t[1000201];
int pr[1000201];


void dfs(int u) {
	if ((int)v[u].size() <= 2) {
		deleted[u] = true;
		for (int j = 0; j < (int)v[u].size(); j++) {
			int h = v[u][j];
			if (!deleted[h]) {
				pr[h] = u;
				dfs(h);
			}
		}
	}
}



int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	pr[0] = -1;
	for (int i = 0; i < n; i++) {
		if ((int)v[i].size() == 1) {
			dfs(i);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			int h = v[i][j];
			if (deleted[h]) {
				t[i] = min(t[i] + 1, 2);
			}
		}
	}
	for (int i = 0; i  < n; i++) {
		if (!deleted[i]) {
			int count = 0;
			for (int j = 0; j < (int)v[i].size(); j++) {
				int h = v[i][j];
				if (!deleted[h]) {
				    if ((int)v[h].size() - t[h] > 1) {
			  	  		count++;
			   	 	}
				}	
			}
			if (count > 2) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
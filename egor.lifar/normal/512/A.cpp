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


using namespace std;


int n;
string s[100];
vector<int> v[27];
vector<int> ans;
bool used[100000];


void dfs(int u) {
	used[u] = true;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int g = v[u][i];
		if (!used[g]) {
			dfs(g);
		}
	}
	ans.push_back(u);
}

int c[26];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i < n; i++) {
		int l = 0;
		while (l < min((int)s[i - 1].size(), (int)s[i].size()) && s[i][l] == s[i - 1][l]) {
			l++;
		} 
		if (l == min((int)s[i - 1].size(), (int)s[i].size())) {
			if (s[i - 1].size() > s[i].size()) {
				cout << "Impossible" << endl;
				return 0;
			}
		} else {
			v[s[i - 1][l] - 'a'].push_back(s[i][l] - 'a');
		}
	}
	for (int i = 0; i < 26; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < 26; i++) {
		c[ans[i]] = i;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < (int)v[i].size(); i++) {
			if (c[v[i][j]] < c[i]) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << char(ans[i] + 'a');
	}
	cout << endl;
  	return 0; 
}
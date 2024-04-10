#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


int n, k;
int x[101], y[101];
string z[101];
vector<int> v[100][5];
int a[101];
long long d[101][101];
bool used[1000][1000];


void dp(int l, int r) {
	if (used[l][r]) {
		return;
	}
	used[l][r] = true;
	
	bool b  = true;
	for (int j = 0; j < (int)v[l][1].size(); j++) {
		if (v[l][1][j] <= l || v[l][1][j] >= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][1].size(); j++) {
		if (v[r][1][j] <= l || v[r][1][j] >= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l][2].size(); j++) {
		if (v[l][2][j] >= l && v[l][2][j] <= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][2].size(); j++) {
		if (v[r][2][j] >= l && v[r][2][j] <= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l][3].size(); j++) {
		if (v[l][3][j] < l || v[l][3][j] > r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][3].size(); j++) {
		if (v[r][3][j] < l || v[r][3][j] > r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l][4].size(); j++) {
		if (v[l][4][j] > l && v[l][4][j] < r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][4].size(); j++) {
		if (v[r][4][j] > l && v[r][4][j] < r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l][0].size(); j++) {
		if (v[l][0][j] != l && v[l][0][j] != r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][0].size(); j++) {
		if (v[r][0][j] != l && v[r][0][j] != r) {
			b = false;
		}
	}
	if (r == l + 1) {
		if (b) {
			d[l][r] = 1;
			return;
		}
		return;
	}
	if (b) {
		//cout << l + 1 << ' ' << r + 1 << endl;
		dp(l + 1, r - 1);
		d[l][r] += d[l + 1][r - 1];
	}
	b = true;
	int r1 = l + 1;
	for (int j = 0; j < (int)v[l][1].size(); j++) {
		if (v[l][1][j] <= l + 1 || v[l][1][j] > r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r1][1].size(); j++) {
		if (v[r1][1][j] <= l + 1 || v[r1][1][j] > r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l][2].size(); j++) {
		if (v[l][2][j] >= l && v[l][2][j] <= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r1][2].size(); j++) {
		if (v[r1][2][j] >= l && v[r1][2][j] <= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l][3].size(); j++) {
		if (v[l][3][j] < l || v[l][3][j] > r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r1][3].size(); j++) {
		if (v[r1][3][j] < l || v[r1][3][j] > r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l][4].size(); j++) {
		if (v[l][4][j] > l + 1 && v[l][4][j] <= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r1][4].size(); j++) {
		if (v[r1][4][j] > l + 1 && v[r1][4][j] <= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l][0].size(); j++) {
		if (v[l][0][j] != l && v[l][0][j] != r1) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r1][0].size(); j++) {
		if (v[r1][0][j] != l && v[r1][0][j] != r1) {
			b = false;
		}
	}
	if (b) {
	//cout << l + 1 << ' ' << r + 1 << endl;
		dp(l + 2, r);
		d[l][r] += d[l + 2][r];
	}
	b = true;
	int l1 = r - 1;
	for (int j = 0; j < (int)v[l1][1].size(); j++) {
		if (v[l1][1][j] < l || v[l1][1][j] >= r - 1) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][1].size(); j++) {
		if (v[r][1][j] < l || v[r][1][j] >= r - 1) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l1][2].size(); j++) {
		if (v[l1][2][j] >= l && v[l1][2][j] <= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][2].size(); j++) {
		if (v[r][2][j] >= l && v[r][2][j] <= r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l1][3].size(); j++) {
		if (v[l1][3][j] < l || v[l1][3][j] > r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][3].size(); j++) {
		if (v[r][3][j] < l || v[r][3][j] > r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l1][4].size(); j++) {
		if (v[l1][4][j] >= l && v[l1][4][j] < r - 1) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][4].size(); j++) {
		if (v[r][4][j] >= l && v[r][4][j] < r - 1) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[l1][0].size(); j++) {
		if (v[l1][0][j] != l1 && v[l1][0][j] != r) {
			b = false;
		}
	}
	for (int j = 0; j < (int)v[r][0].size(); j++) {
		if (v[r][0][j] != l1 && v[r][0][j] != r) {
			b = false;
		}
	}
	if (b) {
		//cout << l + 1 << ' ' << r + 1 << endl;
		dp(l, r - 2);
		d[l][r] += d[l][r - 2];
	}
}	


int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x[i] >> z[i] >> y[i];
		x[i]--;
		y[i]--;
		if (z[i] == "=") {
			v[x[i]][0].push_back(y[i]);
			v[y[i]][0].push_back(x[i]);
		}
		if (z[i] == "<") {
			v[x[i]][1].push_back(y[i]);
			v[y[i]][2].push_back(x[i]);
		} 
		if (z[i] == ">") {
			v[x[i]][2].push_back(y[i]);
			v[y[i]][1].push_back(x[i]);
		} 
		if (z[i] == "<=") {
			v[x[i]][3].push_back(y[i]);
			v[y[i]][4].push_back(x[i]);
		}
		if (z[i] == ">=") {
			v[x[i]][4].push_back(y[i]);
			v[y[i]][3].push_back(x[i]);
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 5; j++) {
			sort(v[i][j].begin(), v[i][j].end());
		}
	}
	dp(0, 2 * n - 1);
	cout << d[0][2 * n - 1] << endl;
    return 0;
}
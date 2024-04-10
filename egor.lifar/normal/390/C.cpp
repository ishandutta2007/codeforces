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


int n, k, w;
int a[100001];
int d[100001][11];


int main() {
	cin >> n >> k >> w;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			a[i] = 1; 
		} else {
			a[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (i > 0) {
				d[i][j] = d[i - 1][j];
			}
			if (j == i % k && a[i] == 1) {
				d[i][j]++;
			}
		}
	}
	for (int i = 0; i < w; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		int sum = 0;
		sum += (r - l + 1) / k - (d[r][r % k] - (l + k - 2 >= 0 ? d[l + k - 2][r % k]: 0));
		for (int j = 0; j < k; j++) {
			if (j != r % k) {
				sum +=  d[r][j] - (l - 1 >= 0 ? d[l - 1][j]: 0);
			}
		}
		cout << sum << endl;
	}
	return 0;
}
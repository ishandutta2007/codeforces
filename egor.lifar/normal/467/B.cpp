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


int n, m, k;
int x[1000];
int x1;
int ans = 0;


int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> x[i];
	}
	cin >> x1;
	for (int i = 0; i < m; i++) {
		int k1 = 0;
		int x2 = x1;
		int x3 = x[i];
		vector<int> v, v1;
		for (int j = 0; j < n; j++) {
			v.push_back(x2 % 2);
			x2 /= 2;
		}
		for (int j = 0; j < n; j++) {
			v1.push_back(x3 % 2);
			x3 /= 2;
		}
		reverse(v.begin(), v.end());
		reverse(v1.begin(), v1.end());
		for (int k2 = 0; k2 < min((int)v.size(), (int)v1.size()); k2++) {
			if (v[k2] != v1[k2]) {
				k1++;
			}
		}
		if (k1 <= k) {
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}
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


int k;
vector<int> v[301];


int main() {
	cin >> k;
	if (k % 2 == 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if (k == 1) {
		cout << 2 << ' ' << 1 << endl;
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 2; i <= k; i++) {
		v[1].push_back(i);
		ans++;
	}
	for (int i = 2; i <= k; i++) {
		int t = i + 2;
		if (i % 2 == 1) {
			t = i + 1;
		}
		for (int j = t; j <= k; j++) {
			v[i].push_back(j);
			ans++;
		}
		v[i].push_back(k + 1);
		v[i].push_back(k + 2);
		ans += 2;
	}
	v[k + 1].push_back(k + 2);
	v[k + 3].push_back(1);
	ans += 2;
	for (int i = 2; i <= k; i++) {
		v[k + 3].push_back(k + 2 + i);
		ans++;
	}
	for (int i = 2; i <= k; i++) {
		int t = i + 2;
		if (i % 2 == 1) {
			t = i + 1;
		}
		for (int j = t; j <= k; j++) {
			v[i + k + 2].push_back(j + k + 2);
			ans++;
		}
		v[i + k + 2].push_back(2 * k + 3);
		v[i + k + 2].push_back(2 * k + 4);
		ans += 2;
	}
	v[2 * k + 3].push_back(2 * k + 4);
	ans ++;
	cout << 2 * k + 4 << ' ' << ans << endl;
	for (int i = 1; i <= 2 * k + 4; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			cout << i << ' ' << v[i][j] << endl;
		}
	}
 	return 0;
}
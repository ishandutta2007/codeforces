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


using namespace std;


int n, k;
int a[5000];
int q;
int s[20];
map<int, int> m;


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (m.find(a[i] * j) == m.end()) {
				m[a[i] * j] = j;
				v.push_back(a[i] * j);
			} else {
				m[a[i] * j] = min(m[a[i] * j], j);
			}
		}
	}
	cin >> q;
//	cout << m[15] << 
	for (int i = 0; i < q; i++) {
		cin >> s[i];
		int ans = 21;
		for (int j = 0; j < (int)v.size(); j++) {
			if (m[s[i] - v[j]] != 0 || s[i] == v[j]) {
				ans = min(ans, m[s[i] - v[j]] + m[v[j]]);
			}
		}
		if (ans > k) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	}

	return 0;
}
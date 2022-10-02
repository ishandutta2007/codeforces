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
#include <vector>
#include <bitset>


using namespace std;


int n;
int a[200001];
int g[200001];
pair<int, int> d[200001], s[200001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		d[i] = make_pair(a[i] - 1, i);
		if (i != n - 1) {
			d[i] = min(d[i], d[i + 1]);
		}
		if (a[i] == 0) {
			g[i] = i;
		} else {
			if (i != n - 1) {
				g[i] = g[i + 1];
			} else {
				g[i] = n;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		s[i] = make_pair(a[i], i);
		if (i != 0) {
			s[i] = min(s[i], s[i - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		long long ans1 = g[i] - i;
		//cout << ans1 << endl;
		if (g[i] == n) {
			ans1 += 1LL * min(d[i].first, s[i].first) * n;
			//cout << ans1 << endl;
			//cout << ans1 << endl;
			//cout << d[i].first << ' ' << s[i].first << endl;
			if (d[i].first < s[i].first) {
				ans1 += 1LL * d[i].second;
			} else {
				ans1 += 1LL * s[i].second;
			}
		}
		ans = max(ans, ans1);
	}
	cout << ans << endl;
	return 0;
}
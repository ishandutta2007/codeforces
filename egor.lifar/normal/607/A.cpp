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
vector<pair<int, int> > v;
int d[200001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	int ans = n;
	for (int i = 0; i < n; i++) {
		int l = 0;
		int r = i;
		while (l != r) {
			int m = (l + r) / 2;
			if (v[i].first - v[m].first > v[i].second) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		d[i] = (l > 0 ? d[l - 1]: 0) + i - l;
		ans = min(ans, d[i] + n - i - 1);
	}
	cout << ans << endl;
	return 0;
}
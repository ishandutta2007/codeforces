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


using namespace std;



int n, m;
vector<int> v[200001];
int d[100001];


int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int c, d;
		scanf("%d %d", &c, &d);
		c--;
		d--;
		v[c].push_back(d);
		v[d].push_back(c);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < (int)v[i].size(); j++) {
			int h = v[i][j];
			if (h < i) {
				d[i] = max(d[i], 1 + d[h]);
			}
		}
		ans = max(ans, 1LL * d[i] * (int)v[i].size());
	}
	cout << ans << endl;
 	return 0;
}
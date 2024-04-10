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


int n, m;


int main() {
	cin >> m >> n;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		int t, T, x, c;
		scanf("%d %d %d %d", &t, &T, &x, &c);
		ans += min(1LL * c + (n + t > T ? 1LL * n * x: 0), (t < T ? 1LL * c * ((n + T - t - 1LL) / (1LL * (T - t))): 100000000000000LL));
	}
	cout << ans << endl;
 	return 0;
}
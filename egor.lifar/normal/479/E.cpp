#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


#define INF 1000000007


int n, k, a, b;
long long d[2][5001];
long long t[5001];


int main() {
	cin >> n >> a >> b >> k;
	d[0][a] = 1;
	for (int i = a; i <= n; i++) {
		t[i] = 1;
	}
	for (int i = 0; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j != b) {
				int k2, k1;
				if (b > j) {
					k2 = min(n, (b + j - 1) / 2);
					k1 = 1;
				} else {
					k2 = n;
					k1 = (b + j + 2) / 2;
				}
				d[1][j] = t[k2] - t[k1 - 1]  - (k2 >= j && k1 <= j ? d[0][j]: 0) - (k2 >= b && b <= j ? d[0][b]: 0);
				d[1][j] = (d[1][j] + 2LL * INF) % INF;
			}
		}
		for (int j = 1; j <= n; j++) {
			d[0][j] = d[1][j];
			t[j] = t[j - 1] + d[0][j];
			t[j] = (t[j] + 10LL * INF) % INF;
		}
	}
	long long ans = 0;
	for (int j = 1; j <= n; j++) {
		ans += d[0][j];
		ans %= INF;
	}
	cout << (ans + 10LL * INF) % INF << endl;
	return 0;
}
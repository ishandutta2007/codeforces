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
#include <math.h>


using namespace std;


int n, k;
int a[5][1000];
int d[1000];
map<int, int> m[5];


int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			m[i][a[i][j]] = j;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			bool b = true;
			for (int k = 0; k < 5; k++) {
				if (m[k][a[0][j]] > m[k][a[0][i]]) {
					b = false;
				}
			}
			if (b) {
				d[i] = max(d[i], 1 + d[j]);
			}
		}
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
    return 0;
}
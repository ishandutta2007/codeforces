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


using namespace std;


int n, k;
int a[101];
int b[101];
int d[101][200001];


int INF =  -1000000000;


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i] *= k;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 200000; j++) {
			d[i][j] = INF;
		}
	}
	d[0][100000] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 200000; j++) {
			if (d[i][j] >= 0) {
				d[i + 1][j] = max(d[i + 1][j], d[i][j]);
				d[i + 1][j + a[i] - b[i]] = max(d[i + 1][j + a[i] - b[i]], d[i][j] + a[i]);
			}
		}
	}
	if (d[n][100000] < 1) {
		cout << -1 << endl;
		return 0;
	}
	cout << d[n][100000] << endl;
    return 0;
}
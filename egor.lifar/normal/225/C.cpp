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
#include <unordered_map>


using namespace std;


int n, m, x, y;
int b[5000];
string a[1001];
int d[2][1001];


int main() {
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i] += (a[j][i] == '.');
		}
	}
	for (int i = 0; i < m; i++) {
		d[0][i] = 1000 * 1000 * 1000;
		d[1][i] = 1000 * 1000 * 1000;
		int sum = 0, sum1 = 0;
		for (int j = i; j >= 0; j--) {
			sum += n - b[j];
			sum1 += b[j];
			if (i - j + 1 >= x && i - j + 1 <= y) {
				d[0][i] = min(d[0][i], sum + (j > 0 ? d[1][j - 1]: 0));
				d[1][i] = min(d[1][i], sum1 + (j > 0 ? d[0][j - 1]: 0));
			}
		}
	}
	cout << min(d[0][m - 1], d[1][m - 1]) << endl;
    return 0;
}
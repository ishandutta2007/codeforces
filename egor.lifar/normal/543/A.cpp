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


int n, m, b, mod;
int a[501];
int d[502][501];


int main(){
	cin >> n >> m >> b >> mod;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int g = 0; g <= b - a[i]; g++) {
				d[j + 1][g + a[i]] = (d[j + 1][g + a[i]] + d[j][g]) % mod;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= b; i++) {
		ans += d[m][i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
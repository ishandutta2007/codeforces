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


int n, m;


int main() {
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (m >= 2 * i) {
			int n1 = n - i;
			int m1 = m - 2 * i;
			ans = max(ans, i + min(m1, n1 / 2));
		}
	}
	cout << ans << endl;
    return 0;
}
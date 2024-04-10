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


using namespace std;


int n, m, a, b;


int main() {
	cin >> n >> m >> a >> b;
	int ans = 1000000000;
	for (int i = 0; i <= n; i++) {
		ans = min(ans, a * i + ((n + m - 1 - i) / m) * b);
	}
	cout << ans << endl;
    return 0;
}
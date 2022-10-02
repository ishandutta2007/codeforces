#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>


using namespace std;


int n, m;
int d[100000], h[100000];


int main() {
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &d[i], &h[i]);
		ans = max(ans, h[i]);
		if (i == 0) {
			ans = max(ans, h[i] + d[i] - 1);
		} else {
			if (d[i] - d[i - 1] < abs(h[i] - h[i - 1])) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			} 
			ans = max(ans, max(h[i], h[i - 1]) + (d[i] - d[i - 1] - abs(h[i] - h[i - 1])) / 2);
		}
	}
	ans = max(ans, h[m - 1] + n - d[m - 1]);
	cout << ans << endl;
    return 0;	
}
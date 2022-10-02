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
int a[101][101];


int main() {
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			if (a + b >= 1) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
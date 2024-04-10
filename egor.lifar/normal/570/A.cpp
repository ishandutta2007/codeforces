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


int n, m;
int c[1000][1000];
int g[1000];


int main() {
	cin >> n >> m;
	int sum1 = 0;
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &c[i][j]);
			sum = max(sum, c[i][j]);
		}
		sum1 = max(sum1, sum);
		for (int j = 0; j < n; j++) {
			if (c[i][j] == sum) {
				g[j]++;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, g[i]);
	}
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (ans == g[i]) {
			r = i + 1;
			break;
		}
	}
	cout << r << endl;
    return 0;
}
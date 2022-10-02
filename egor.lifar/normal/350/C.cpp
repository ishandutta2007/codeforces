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


int n;
pair<int, pair<int, int> > g[100000];


int main() {
	cin >> n;
	int t = 6 * n;
	for (int i = 0; i < n; i++) {
		cin >> g[i].second.first >> g[i].second.second;
		g[i].first = abs(g[i].second.first) + abs(g[i].second.second);
		if (g[i].second.first == 0) {
			t-= 2;
		}
		if (g[i].second.second == 0) {
			t-= 2;
		}
	}
	sort(g, g + n);
	printf("%d\n", t);
	for (int i = 0; i < n; i++) {
		int x = g[i].second.first;
		int y = g[i].second.second;
		if (x > 0) {
			printf("%d %d %c\n", 1, x, 'R');
		}
		if (x < 0) {
			printf("%d %d %c\n", 1, -1 * x, 'L');
		}
		if (y > 0) {
			printf("%d %d %c\n", 1, y, 'U');
		}
		if (y < 0) {
			printf("%d %d %c\n", 1, -1 * y, 'D');
		}
		printf("%d\n", 2);
		if (x < 0) {
			printf("%d %d %c\n", 1, -1 * x, 'R');
		}
		if (x > 0) {
			printf("%d %d %c\n", 1, x, 'L');
		}
		if (y < 0) {
			printf("%d %d %c\n", 1, -1 * y, 'U');
		}
		if (y > 0) {
			printf("%d %d %c\n", 1, y, 'D');
		}
		printf("%d\n", 3);
	}
    return 0;
}
#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <queue>


using namespace std;


int q;
int a[1001][1001];


int main() {
	cin >> q;
	for (int ii = 0; ii < q; ii++) {
		int h, w;
		scanf("%d %d", &h, &w);
		int sumdist = 0, sumdist1 = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int j = 0; j < w; j++) {
			sumdist += abs(a[h / 2 - 1][j] - a[h / 2][j]);
		}
		for (int j = 0; j < w; j++) {
			sumdist1 += abs(a[0][j] - a[h - 1][j]);
		}
		if (sumdist > sumdist1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
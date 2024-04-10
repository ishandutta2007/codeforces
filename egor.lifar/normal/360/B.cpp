#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n, k;
int a[2002];
int d[2002];


int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (k == n || k == n - 1) {
		printf("0\n");
		return 0;
	}
	int l = 0;
	int r = 2000000000;
	for (int iii = 0; iii < 33; iii++) {
		int m = (1LL * l + 1LL * r) >> 1;
		int ans = n - 1;
		for (int i = 1; i < n; i++) {
			d[i] = i;
			for (int j = i - 1; j >= 0; j--) {
				if ((abs(a[i] - a[j]) + i - j - 1) / (i - j) <= m) {
					d[i] = min(d[i], d[j] + i - j - 1);
				} 
			}
			ans = min(ans, d[i] + n - i - 1);
		}
		if (ans <= k) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	printf("%d\n", max(l, r));
	return 0;
}
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


#define M 1000000000


int n, m;
int a[1000000];
int f[1000001];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % M;
	}
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, v;
			scanf("%d %d", &x, &v);
			a[x - 1] = v;
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			l--;
			r--;
			int ans = 0;
			for (int j = l; j <= r; j++) {
				ans += (1LL * f[j - l] * a[j]) % M;
				ans %= M;
			}
			printf("%d\n", ans);
		}
	}
 	return 0;
}
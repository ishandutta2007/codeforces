#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;


int n, m;
int r[100000];
int s[100000];
int a[100000];
int br[100000];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int l = (int)sqrt(n);
	for (int i = n - 1; i >= 0; i--) {
		int g = (i / l) * l;
		if (i + a[i] >= min(g + l, n)) {
			r[i] = i + a[i];
			s[i] = 1;
			br[i] = i;
		} else {
			r[i] = r[i + a[i]];
			s[i] = 1 + s[i + a[i]];
			br[i] = br[i + a[i]];
		}
	}
	for (int k = 0; k < m; k++) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int gg, gg1;
			scanf("%d %d", &gg, &gg1);
			a[gg - 1] = gg1;
			int v = (gg - 1) / l * l;
			int h = min(n, v + l);
			for (int i = h - 1; i >= v; i--) {
				if (a[i] + i >= h) {
					s[i] = 1;
					r[i] = a[i] + i;
					br[i] = i;
				} else {
					s[i] = 1 + s[a[i] + i];
					br[i] = br[a[i] + i];
					r[i] = r[a[i] + i];
				}
			}
		} else {
			int gg;
			scanf("%d", &gg);
			gg--;
			int ans = 0;
			int p = 0;
			while (r[gg] < n) {
				ans += s[gg];
				gg = r[gg];
			}
			p = br[gg];
			ans += s[gg];
			printf("%d %d\n", p + 1, ans);
		}
	}
    return 0;
}
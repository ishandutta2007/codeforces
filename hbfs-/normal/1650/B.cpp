#include <bits/stdc++.h>
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	int T; scanf("%d",&T);
	while (T--) {
		int l = rd(), r = rd(), a = rd();
		int xl = l / a, xr = r / a;
		int yl = l % a, yr = r % a;
		int ans = 0;
		if (xl == xr) {
			ans = xr+yr;
		} else {
			if (yr == a-1) {
				ans = xr+yr;
			} else {
				ans = xr-1+a-1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
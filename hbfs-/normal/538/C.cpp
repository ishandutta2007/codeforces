#include <bits/stdc++.h>
#define N 1000050
using namespace std;
int n,m,a[N],b[N],ans;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd(), m = rd();
	for (int _=1;_<=m;_++) a[_] = rd(), b[_] = rd();
	for (int _=2;_<=m;_++) {
		int c = abs(b[_] - b[_-1]), d = a[_] - a[_-1];
		if (c > d) return puts("IMPOSSIBLE"), 0;
		ans = max(ans, max(b[_], b[_-1]) + (d-c)/2);
	}
	ans = max(ans, a[1]+b[1]-1);
	ans = max(ans, n-a[m]+b[m]);
	cout << ans << endl;
	return 0;
}
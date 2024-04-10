#include <bits/stdc++.h>
#define N 2050
using namespace std;
int n, ans[N], d[N], a[N], b[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) ans[i] = 0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=i;i<=n;i++) d[ a[i] ] = i;
		int cur = n;
		for (int i=n;i>=1;i--) {
			int x = -1;
			for (int j=1;j<=i;j++)
				if (a[j] == i) {
					x = j;
				}
			if (x == i) continue;
			ans[i] = x;
			int tot = 0;
			for (int j=x+1;j<=i;j++)
				b[++tot] = a[j];
			for (int j=1;j<=x-1;j++)
				b[++tot] = a[j];
			for (int j=1;j<=i;j++) a[j] = b[j];
		}
		for (int i=1;i<=n;i++) printf("%d%c", ans[i], i==n?'\n':' ');
	
	}
	return 0;
	
}
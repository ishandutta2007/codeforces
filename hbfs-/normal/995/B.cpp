#include <bits/stdc++.h>
#define N 205
using namespace std;
int a[N],p[N],vis[N],n,ans;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd();
	for (int i=1;i<=2*n;i++) a[i] = rd();
	for (int i=1;i<=2*n;i++) {
		if (p[ a[i] ]) continue;
		for (int j=i+1;j<=2*n;j++) {
			if (a[j] == a[i]) {
				p[ a[j] ] = 1;
				vis[j] = 1;
				break;
			}
			if (!vis[j]) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
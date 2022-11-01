#include <bits/stdc++.h>
#define N 1000050

using namespace std;
inline int rd() { int r; scanf("%d",&r); return r; }
int n,m,a[N],b[N],sum[N],F[N];
int main() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = rd() , sum[ a[i] ]++ , F[ a[i] ]++;
	for (int i=1;i<=n;i++) b[i] = rd() , sum[ b[i] ]++;
	
	int ans = 0;
	for (int i=1;i<=5;i++) {
		if (sum[i]&1) { puts("-1"); return 0; }
		int cur = sum[i] >> 1;
		if (F[i] - cur > 0) ans += F[i] - cur;
	}
	printf("%d\n",ans);
	return 0;
}
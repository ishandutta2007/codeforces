#include <bits/stdc++.h>
typedef long long LL;
#define N 2000500
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int n,a[N];
int main() {
	n = rd();
	for (int i=1;i<=2*n;i++) a[i] = rd();
	sort(a+1,a+2*n+1);
	LL ans = 1LL * (a[n]-a[1]) * (a[2*n]-a[n+1]);
	for (int i=1;i<=n;i++) ans = min(ans, 1LL*(a[n+i]-a[1+i]) * (a[2*n]-a[1]));
	cout << ans << endl;
	return 0;
}
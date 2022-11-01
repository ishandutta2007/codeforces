#include <bits/stdc++.h>
#define N 1000500
#define mod 998244353
using namespace std;
typedef long long LL;
int n, ans;
LL sum[N], a[N];
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd();
	for (LL i=1;i<=n;i++) a[i] = rd();
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	for (LL i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];	
	LL L = 0, R = n;
	for (LL i=1;i<=n;i++) {
		LL j = lower_bound(a+i+1, a+n+1, i, greater<LL>()) - a;
		LL a = sum[i] - ans;
		LL b = i*(i-1) + sum[n] - sum[j-1] + 1LL * (j-i-1) * i;
		if (a > b) {
			if (a-b-i>0) {
				puts("-1");
				return 0;
			}
			L = max(a-b, L);
		}
		R = min(R, j-(a-b-i));
	}
	if (sum[n] & 1) {
		if (!(L&1)) L++;
		if (!(R&1)) R--;
	} else {
		if (L&1) L++;
		if (R&1) R--;
	}

	if (L > R) {
		puts("-1");
		return 0;
	}
	for (int i=L;i<=R;i+=2) printf("%d%c",i,i==R?'\n':' ');
	return 0;
}
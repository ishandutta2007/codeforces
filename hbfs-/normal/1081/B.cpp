#include <bits/stdc++.h>
#define N 1000500
using namespace std;
int a[N],b[N],F[N],sum[N],L,R,n,cnt;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = n - rd();
	for (int i=1;i<=n;i++) sum[ a[i] ]++;

	int flag = 1;
	for (int i=1;i<=n;i++) if (sum[i] % i != 0) flag = 0;
	if (!flag) {
		puts("Impossible");
		return 0;
	}

	int num = 0;
	for (int i=1;i<=n;i++) {
		int t = a[i];
		if (sum[t] % t == 0) F[t] = ++num;
		b[i] = F[t];
		sum[t]--;
	}
	puts("Possible");
	for (int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
	return 0;
}
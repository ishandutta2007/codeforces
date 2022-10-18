#include <bits/stdc++.h>

int n,l[300005],r[300005],rk[300005];

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d",&l[i],&r[i]);
		rk[i] = i;
	} std::sort(rk+1,rk+n+1,[](int a,int b){return l[a] != l[b] ? l[a] < l[b] : r[a] > r[b];});
	int max = 0;
	for (int i = 1; i <= n; ++ i) {
		if (r[max] >= r[rk[i]]) {
			printf("%d %d\n",rk[i],max); return 0;
		} if (r[max] <= r[rk[i]]) max = rk[i];
	} printf("-1 -1");
	return 0;
}
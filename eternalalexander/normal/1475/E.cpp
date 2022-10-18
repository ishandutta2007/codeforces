#include <bits/stdc++.h>

const int mod = 1e9+7;
int n,k,C[1005][1005],vis[1005],a[1005];

void solve() {
	scanf("%d%d",&n,&k);
	for (int i = 0; i <= n; ++ i) {
		vis[i] = 0;
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		vis[a[i]] ++;
	} for (int i = n; i >= 1; i --) {
		if (k > vis[i]) k -= vis[i];
		else {
		//	printf("(%d %d)\n",vis[i],k);
			printf("%d\n",C[vis[i]][k]);
			return ;
		}
	}
}
	

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}
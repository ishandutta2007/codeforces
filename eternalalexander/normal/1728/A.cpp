#include <bits/stdc++.h>

int n,cnt[1000];

int main() {
	int t;scanf("%d",&t);while (t--){
		scanf("%d",&n);
		for (int i = 1; i <= n; ++ i) scanf("%d",&cnt[i]);
		printf("%d\n",std::max_element(cnt + 1,cnt + n + 1) - (cnt));
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int cnt[100010];

int main(){
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	int ans = 0;
	for (int i = 1; i <= k; i++){
		ans += cnt[i] & 1;
	}
	printf("%d\n", n - (ans - (n & 1)) / 2);
	return 0;
}
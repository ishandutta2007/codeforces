#include <bits/stdc++.h>
using namespace std;

int a[1010];
bitset <1010> dp;
int in[1010];

int main(){
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		in[a[i]]++;
	}
	dp[0] = 1;
	int pos = 0;
	for (int i = 1; i <= n; i++){
		if (in[i]) continue;
		int now = i, cnt = 1, flag = 1;
		if (i == k) flag = 0, pos = cnt;
		while (a[now]){
			now = a[now], cnt++;
			if (now == k) flag = 0, pos = cnt;
		}
		if (flag) dp |= dp << cnt;
		else pos = cnt - pos + 1;
	}
	for (int i = 0; i <= n; i++){
		if (dp[i]) printf("%d\n", i + pos);
	}
	return 0;
}
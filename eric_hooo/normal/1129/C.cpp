#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

typedef unsigned long long ull;

long long dp[3010];
int a[3010];

struct Hash_table{
	const int MOD = 1000003;
	int head[1000003];
	ull to[10000000];
	int nxt[10000000];
	int tot;
	void init(){
		tot = 0, memset(head, -1, sizeof(head));
	}
	bool has(ull x){
		int p = x % MOD;
		for (int i = head[p]; ~i; i = nxt[i]){
			if (to[i] == x) return 1;
		}
		return 0;
	}
	void add(ull x){
		int p = x % MOD;
		to[tot] = x, nxt[tot] = head[p], head[p] = tot++; 
	}
}H;

bool isok(int x){
	if (a[x] == 0 && a[x + 1] == 0 && a[x + 2] == 1 && a[x + 3] == 1) return 0;
	if (a[x] == 0 && a[x + 1] == 1 && a[x + 2] == 0 && a[x + 3] == 1) return 0;
	if (a[x] == 1 && a[x + 1] == 1 && a[x + 2] == 1 && a[x + 3] == 0) return 0;
	if (a[x] == 1 && a[x + 1] == 1 && a[x + 2] == 1 && a[x + 3] == 1) return 0;
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	H.init();
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		memset(dp, 0, sizeof(dp));
		dp[i + 1] = 1;
		ull h = 0;
		for (int j = i; j >= 1; j--){
			dp[j] = (dp[j + 1] + dp[j + 2] + dp[j + 3]) % mod;
			if (isok(j)) dp[j] = (dp[j] + dp[j + 4]) % mod;
			h = h * 3 + a[j] + 1;
			if (!H.has(h)) H.add(h), ans = (ans + dp[j]) % mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
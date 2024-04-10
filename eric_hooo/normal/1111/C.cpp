#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long mod = 10000019;

int a[100010];
long long cnt[3000010];
long long dp[3000010];
int head[10000019];
long long to[3000010];
int nxt[3000010];
int n, k, A, B;
int tot = 1;

int get_id(long long x){
	int p = x % mod;
	for (int i = head[p]; i; i = nxt[i]){
		if (to[i] == x) return i;
	}
	to[tot] = x, nxt[tot] = head[p], head[p] = tot++;
	return tot - 1;
}

ll key(long long x, long long y){
	return x << 31 | y;
}

long long get_dp(long long x){
	int p = x % mod;
	for (int i = head[p]; i; i = nxt[i]){
		if (to[i] == x) return dp[i];
	}
	return A;
}

void dfs(int l, int r, int x){
//	cout << "dfs:" << l << " " << r << " " << x << endl;
	if (l == r){
		int id = get_id(key(l, r));
//		cout << "  " << l << " " << r << " " << id << endl;
		cnt[id]++;
		dp[id] = cnt[id] * B;
		return ;
	}
	int mid = l + r >> 1;
	if (x <= mid) dfs(l, mid, x);
	else dfs(mid + 1, r, x);
	int id = get_id(key(l, r));
	cnt[id]++;
//	cout << "  cnt:" << l << " " << r << " " << cnt[id] << endl;
	dp[id] = min(get_dp(key(l, mid)) + get_dp(key(mid + 1, r)), 1ll * cnt[id] * B * (r - l + 1));
}

int main(){
	scanf("%d%d%d%d", &n, &k, &A, &B);
	for (int i = 0; i < k; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < k; i++){
		dfs(1, 1 << n, a[i]);
	}
//	cout << "  id:" << get_id(key(1, 1)) << endl;
//	cout << "  dp:" << get_dp(key(1, 1)) << endl;
	printf("%I64d\n", dp[get_id(key(1, 1 << n))]);
	return 0;
}
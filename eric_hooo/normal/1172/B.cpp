#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

vector <int> from[200010];
long long cnt[200010];
long long pw[200010];

long long dfs(int x, int last){
	long long ans = 1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		ans = ans * dfs(v, x) % mod * (cnt[v] + 1) % mod;
		cnt[x]++;
	}
	ans = ans * pw[cnt[x]] % mod;
	return ans;
}

int main(){
	int n; scanf("%d", &n);
	pw[0] = 1;
	for (int i = 1; i <= n; i++){
		pw[i] = pw[i - 1] * i % mod;
	}
	for (int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	printf("%I64d\n", dfs(1, 1) * n % mod);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const long long INF = 100000000000000000;

long long a[100010], b[100010], k[100010];
vector <int> from[100010];

long long dfs(int x){
	long long sum = a[x] - b[x];
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		long long val = dfs(v);
		sum += val;
		if (sum < -INF) sum = -INF;
	}
	if (x == 1) return sum;
	if (sum < 0){
		if (INF / k[x] > -sum) sum *= k[x];
		else sum = -INF;
	}
	return sum;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++){
		scanf("%lld", &b[i]);
	}
	for (int i = 2; i <= n; i++){
		int x; scanf("%d%lld", &x, &k[i]);
		from[x].push_back(i);
	}
	printf(dfs(1) >= 0 ? "YES\n" : "NO\n");
	return 0;
}
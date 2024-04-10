#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> piii;

piii a[250010];
int sum[510][510];
int n, m, k, q;

int get_sum(int a, int b, int c, int d){
	return sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
}

bool check(int x){
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i <= x; i++){
		sum[a[i].se.fi][a[i].se.se] = 1;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n - k + 1; i++){
		for (int j = 1; j <= m - k + 1; j++){
			if (get_sum(i, j, i + k - 1, j + k - 1) == k * k) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < q; i++){
		scanf("%d%d%d", &a[i].se.fi, &a[i].se.se, &a[i].fi);
	}
	sort(a, a + q);
	if (!check(q - 1)){
		printf("-1\n");
		return 0;
	}
	int l = k * k - 1, r = q - 1;
	while (l < r){
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", a[l].fi);
	return 0;
}
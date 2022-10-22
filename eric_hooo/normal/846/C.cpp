#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pli;

int a[5010];
long long sum[5010];
pli maxj[5010];
int n;

long long get_sum(int a, int b, int c){
	return sum[a - 1] - (sum[b - 1] - sum[a - 1]) + (sum[c - 1] - sum[b - 1]) - (sum[n] - sum[c - 1]);
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = n; i >= 0; i--){
		maxj[i] = mp(sum[i], i + 1);
		if (i != n) maxj[i] = max(maxj[i], maxj[i + 1]);
	}
	int i, j, k;
	long long ans = -0x3f3f3f3f;
	for (int x = 1; x <= n + 1; x++){
		for (int y = x; y <= n + 1; y++){
			int z = maxj[y - 1].se;
			if (get_sum(x, y, z) > ans){
				ans = get_sum(x, y, z);
				i = x, j = y, k = z;
			}
		}
	}
	printf("%d %d %d\n", i - 1, j - 1, k - 1);
	return 0;
}
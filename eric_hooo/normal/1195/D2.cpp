#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int a[100010];
int sum[20];

int count(int x){
	int cnt = 0;
	while (x) cnt++, x /= 10;
	return cnt;
}

long long power(int a, int b){
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum[count(a[i])]++;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= 10; j++){
			for (int k = 0; k <= 10; k++){
				ans = (ans + a[i] % 10 * sum[k] * power(10, min(j * 2, j + k))) % mod;
				ans = (ans + a[i] % 10 * sum[k] * power(10, min(j * 2 + 1, j + k))) % mod;
			}
			a[i] /= 10;
			if (!a[i]) break;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
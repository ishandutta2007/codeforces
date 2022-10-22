#include <bits/stdc++.h>
using namespace std;

int mod;
int a[510];
long long f[510][510];

int main(){
	int n, m, b;
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	f[0][0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = a[i]; k <= b; k++){
				f[j][k] = (f[j][k] + f[j - 1][k - a[i]]) % mod;
			}
		}
	}
	long long ans = 0;
	for (int k = 0; k <= b; k++){
		ans = (ans + f[m][k]) % mod;
	}
	printf("%I64d\n", ans);
	return 0;
}
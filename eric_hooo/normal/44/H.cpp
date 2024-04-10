#include <bits/stdc++.h>
using namespace std;

long long f[20][60][60];
int a[60], n;

bool my(){
	for (int i = 1; i < n; i++){
		int t = a[i] + a[i - 1];
		if (t / 2 != a[i] && (t + 1) / 2 != a[i]) return 0;
	}
	return 1;
}

int main(){
	char buf[100];
	scanf("%s", buf);
	n = strlen(buf);
	for (int i = 0; i < n; i++){
		a[i] = buf[i] - '0';
	}
	long long ans = 0;
	for (int p = 0; p <= 9; p++){
		f[p][0][p] = 1;
		for (int i = 1; i < n; i++){
			for (int j = 0; j <= 9; j++){
				int t = a[i] + j;
				f[p][i][t / 2] += f[p][i - 1][j];
				if ((t + 1) / 2 != t / 2) f[p][i][(t + 1) / 2] += f[p][i - 1][j];
			}
		}
		for (int i = 0; i <= 9; i++){
			ans += f[p][n - 1][i];
		}
	}
	if (my()) ans--;
	printf("%I64d\n", ans);
	return 0;
}
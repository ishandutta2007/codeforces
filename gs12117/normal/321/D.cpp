#include<stdio.h>
int n;
int a[34][34];
int hn;
int ans;
void bcalc() {
	int res = 0;
	for (int i = 0; i < n; i++)res += a[hn - 1][i];
	for (int i = 0; i + hn < n; i++) {
		int tres;
		int pres = a[i][hn - 1] + a[i + hn][hn - 1];
		for (int j = 0; j < hn - 1; j++) {
			int t = a[i][j] + a[i + hn][j] + a[i][j + hn] + a[i + hn][j + hn];
			if (t < 0)pres -= t;
			else pres += t;
		}
		tres = pres;
		pres = -a[i][hn - 1] - a[i + hn][hn - 1];
		for (int j = 0; j < hn - 1; j++) {
			int t = -a[i][j] - a[i + hn][j] + a[i][j + hn] + a[i + hn][j + hn];
			if (t < 0)pres -= t;
			else pres += t;
		}
		if (tres > pres)res += tres;
		else res += pres;
	}
	if (ans < res)ans = res;
}
void calc(int dep) {
	if (dep == hn) {
		bcalc();
	}
	else {
		calc(dep + 1);
		for (int i = dep; i < dep + hn; i++) {
			for (int j = 0; j < hn; j++) {
				a[j][i] = -a[j][i];
			}
		}
		calc(dep + 1);
		for (int i = dep; i < dep + hn; i++) {
			for (int j = 0; j < hn; j++) {
				a[j][i] = -a[j][i];
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	hn = n / 2 + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	calc(0);
	printf("%d", ans);
	return 0;
}
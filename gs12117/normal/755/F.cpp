#include<cstdio>
#include<bitset>
#include<vector>
int n, m;
int a[1001000];
int ansa, ansb;
int chk[1001000];
int cln[1001000];
std::bitset<1001000> dptable;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (chk[i] == 1)continue;
		int p = i;
		int j;
		for (j = 0; chk[p] == 0; j++) {
			chk[p] = 1;
			p = a[p];
		}
		cln[j]++;
	}
	int ocn = 0;
	for (int i = 0; i <= n; i++) {
		if (i % 2 == 1) {
			ocn += cln[i];
		}
	}
	if (m < (n - ocn) / 2)ansb = m * 2;
	else if (m < (n - ocn) / 2 + ocn)ansb = m + (n - ocn) / 2;
	else ansb = n;
	dptable[0] = 1;
	for (int i = 0; i <= n; i++) {
		while (cln[i] > 2) {
			cln[i] -= 2;
			cln[i * 2]++;
		}
		for (int j = 0; j < cln[i]; j++) {
			dptable |= (dptable << i);
		}
	}
	if (dptable[m]) {
		ansa = m;
	}
	else {
		ansa = m + 1;
	}
	printf("%d %d\n", ansa, ansb);
	return 0;
}
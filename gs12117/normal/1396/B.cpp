#include<cstdio>
int n;
int a[110];
int main() {
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int maxa = 0;
		int suma = 0;
		for (int i = 0; i < n; i++) {
			suma += a[i];
			if (maxa < a[i])maxa = a[i];
		}
		int res = suma % 2;
		if (maxa > suma - maxa)res = 1;
		if (res == 1) {
			printf("T\n");
		}
		else {
			printf("HL\n");
		}
	}
	return 0;
}
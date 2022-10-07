#include<cstdio>
#include<cmath>
int n, r;
int a[1010];
double ans[1010];
int main() {
	scanf("%d%d", &n, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		ans[i] = r;
		for (int j = 0; j < i; j++) {
			int dist = a[i] - a[j];
			if (dist < 0)dist = -dist;
			if (dist <= 2 * r) {
				double pres;
				if (dist == 2 * r) {
					pres = 0;
				}
				else {
					pres = sqrt(4 * r*r - dist*dist);
				}
				pres += ans[j];
				if (pres > ans[i])ans[i] = pres;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%.20lf ", ans[i]);
	}
	return 0;
}
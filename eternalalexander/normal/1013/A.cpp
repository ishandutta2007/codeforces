#include <cstdio>

int x[100], y[100];
int sum1=0; int sum2=0;
int main() {
	int n;
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d", &x[i]); sum1+=x[i];
	}
	for (int i=1;i<=n;++i) {
		scanf("%d", &y[i]); sum2+=y[i];
	}if (sum1>=sum2) printf("Yes");
	else printf("No");
	return 0;
}
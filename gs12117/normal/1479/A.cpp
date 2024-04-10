#include<cstdio>
int n;
int incdec(int x) {
	int ta, tb;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &ta);
	printf("? %d\n", x + 1);
	fflush(stdout);
	scanf("%d", &tb);
	if (ta < tb) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("! %d\n", 1);
		return 0;
	}
	int tres = incdec(1);
	if (tres == 1) {
		printf("! %d\n", 1);
		return 0;
	}
	tres = incdec(n - 1);
	if (tres == 0) {
		printf("! %d\n", n);
		return 0;
	}
	int l = 1;
	int r = n - 1;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		tres = incdec(m);
		if (tres == 1) {
			r = m;
		}
		else {
			l = m;
		}
	}
	printf("! %d\n", r);
	return 0;
}
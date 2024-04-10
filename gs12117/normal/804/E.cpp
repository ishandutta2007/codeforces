#include<cstdio>
int n;
int a[1010];
int chk[1010];
void swp(int x, int y) {
	if (x == y)return;
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
	printf("%d %d\n", x + 1, y + 1);
}
int main() {
	scanf("%d", &n);
	if (n % 4 == 2 || n % 4 == 3) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	int flag = 0;
	int pa, pb;
	for (int i = 0; i < n; i++) {
		int p = 0;
		if (flag == 1) {
			p = pa;
		}
		else {
			for (int j = 0; j < n; j++) {
				if (chk[j] == 0) {
					p = j;
					break;
				}
			}
		}
		chk[p] = 1;
		if (flag == 1) {
			flag = 0;
			int ppb = pb;
			int lstp = -1;
			for (int j = 0; j < n; j++) {
				if (a[j] == p) {
					lstp = j;
				}
			}
			if (lstp == p) {
				pa = -1;
				for (int j = 0; j < n; j++) {
					if (chk[j] == 0&&j!=ppb) {
						if (pa == -1)pa = j;
						pb = j;
					}
				}
				for (int j = 0; j < n; j++) {
					if (chk[j] == 0 && j != ppb && j != pb) {
						swp(p, j);
					}
				}
				if (pa != -1) {
					swp(pa, pb);
					swp(p, pb);
					flag = 1;
				}
			}
			else if (lstp == ppb) {
				pa = ppb;
				for (int j = 0; j < n; j++) {
					if (chk[j] == 0 && j != ppb) {
						pb = j;
					}
				}
				for (int j = 0; j < n; j++) {
					if (chk[j] == 0 && j != ppb && j != pb) {
						swp(p, j);
					}
				}
				if (pa != -1) {
					swp(pa, pb);
					swp(p, pb);
					flag = 1;
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					if (chk[j] == 0 && j != ppb && j != lstp) {
						swp(p, j);
					}
				}
				swp(p, lstp);
			}
		}
		else {
			int lstp = -1;
			for (int j = 0; j < n; j++) {
				if (a[j] == p) {
					lstp = j;
				}
			}
			if (lstp == p) {
				pa = -1;
				for (int j = 0; j < n; j++) {
					if (chk[j] == 0) {
						if (pa == -1)pa = j;
						pb = j;
					}
				}
				for (int j = 0; j < n; j++) {
					if (chk[j] == 0 && j != pb) {
						swp(p, j);
					}
				}
				if (pa != -1) {
					swp(pa, pb);
					swp(p, pb);
					flag = 1;
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					if (chk[j] == 0&&j!=lstp) {
						swp(p, j);
					}
				}
				swp(p, lstp);
			}
		}
	}
	return 0;
}
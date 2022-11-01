#include <bits/stdc++.h>
#define N 1000500
using namespace std;
int n,t,c,cst,x;
int s[N], F[N];
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd(), t = rd();
	cst = t;
	for (int i=1;i<n;i++) {
		int flag = 1;
		int c0 = c;
		for (int j=1;j<=32;j++) {
			printf("? %d %d\n", i+1, n);
			fflush(stdout);
			x = rd();
			if (x != n-t) {
				for (int _=1;_<j;_++) {
					for (int p=1;p<=n;p++) F[p] ^= 1;
				}
				for (int p=i+1;p<=n;p++) F[p] ^= 1;
				flag = 0;
				break;
			}
			t = x;
			c = i-1-c;
		}
		if (flag) {
			if (c0 == i / 2)
				s[i] = 0 ^ F[i];
			else
				s[i] = 1 ^ F[i];
			c = i / 2;
		} else {
			if (x == n-i-t+2*(c+1))
				s[i] = 1 ^ F[i], c++;
			else
				s[i] = 0 ^ F[i];
			t = x;
		}
	}

	for (int i=1;i<n;i++) cst -= s[i];
	s[n] = cst;

	printf("! ");
	for (int i=1;i<=n;i++) printf("%d",s[i]);
	putchar('\n');
	fflush(stdout);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;


int ps[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int ddd = -1;

char rd[11000];

void solve() {
	for (int i = 0; i < 15; i++) {
		printf("%d\n", ps[i]);
		fflush(stdout);

		scanf("%s", rd);
		if (strcmp(rd, "yes") == 0) {
			if (ddd == -1) ddd = ps[i];
			else {
				printf("composite\n");
				fflush(stdout);
				return;
			}
		}
	}

	if (ddd != -1 && ddd*ddd <= 100) {
		printf("%d\n", ddd*ddd);
		fflush(stdout);

		scanf("%s", rd);
		if (strcmp(rd, "yes") == 0) {
			printf("composite\n");
			fflush(stdout);
			return;
		}
	}

	printf("prime\n");
	fflush(stdout);
}

int main() {
    solve();
}
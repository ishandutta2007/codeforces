#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	int n, k, odg;
	scanf("%d%d", &n, &k);
	printf("? 1\n");
	fflush(stdout);
	scanf("%d", &odg);
	int poz = 1, korak = 1;
	while(1) {
		printf("? %d\n", poz);
		fflush(stdout);
		scanf("%d", &odg);
		if(odg != k) break;
		poz += korak;
		korak++;
		while(poz > n) poz -= n;
	}
	int l, r, mid;
	if(odg < k) {
		l = poz;
		r = poz + korak;
		while(l < r) {
			mid = (l + r) / 2;
			printf("? %d\n", (mid - 1) % n + 1);
			fflush(stdout);
			scanf("%d", &odg);
			if(odg < k) l = mid + 1;
			else if(odg > k) r = mid - 1;
			else {
				printf("! %d\n", (mid - 1) % n + 1);
				fflush(stdout);
				exit(0);
			}
		}
		printf("! %d\n", (l - 1) % n + 1);
		fflush(stdout);
		exit(0);
	}
	else {
		r = poz;
		l = poz - korak;
		if(l < 1) {
			l += n;
			r += n;
		}
		while(l < r) {
			mid = (l + r) / 2;
			printf("? %d\n", (mid - 1) % n + 1);
			fflush(stdout);
			scanf("%d", &odg);
			if(odg < k) l = mid + 1;
			else if(odg > k) r = mid - 1;
			else {
				printf("! %d\n", (mid - 1) % n + 1);
				fflush(stdout);
				exit(0);
			}
		}
		printf("! %d\n", (l - 1) % n + 1);
		fflush(stdout);
		exit(0);
	}
	return 0;
}
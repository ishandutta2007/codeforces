#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int main() {
	int n, q, a, b, x = 0, xPar = 0;
	scanf("%d %d", &n, &q);
	while(q--) {
		scanf("%d", &a);
		if(a == 1) {
			scanf("%d", &b);
			x += b;
			if(x >= n) {
				x = x % n;
			} else if(x < 0) {
				x = n - ((x*-1) % n);
			}
		} else {
			if((x + xPar) % 2 == 1) {
				xPar = ((xPar + 1) % n);
			} else {
				if(--xPar < 0) {
					xPar += n;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		int nTemp = i+x;
		if(i % 2) {
			nTemp -= xPar;
		} else {
			nTemp += xPar;
		}
		while(nTemp <= 0) {
			nTemp += n;
		}
		while(nTemp > n) {
			nTemp -= n;
		}
		//printf("%d %d\n", i, nTemp);
		arr[nTemp] = i;
	}
	for(int i = 1; i <= n; i++) {
		cout << arr[i];
		if(i != n) {
			cout << " ";
		}
	}
	//printf("\n%d %d %d\n", n, xPar, x);
	return 0;
}
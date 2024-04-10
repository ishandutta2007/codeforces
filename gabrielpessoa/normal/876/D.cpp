#include <bits/stdc++.h>
using namespace std;

bool arr[300005];

int main() {
	int n, total, x, maior;
	scanf("%d", &n);
	maior = n;
	cout << 1;
	for(int i = n-1; i >= 0; i--) {
		scanf("%d", &x);
		arr[x] = true;
		for(int c = maior; c >= 0; c--) {
			if(!arr[c]) {
				maior = c;
				break;
			}
		}
		//printf("\n%d %d", i, maior);
		printf(" %d", maior - (i-1));
	}
}
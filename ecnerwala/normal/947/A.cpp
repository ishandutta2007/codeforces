#include<bits/stdc++.h>
using namespace std;

const int MAXV = 2e6;
int max_prime[MAXV];

int main() {
	int X2; scanf("%d", &X2);
	max_prime[1] = 1;
	for (int i = 2; i <= X2; i++) {
		if (max_prime[i]) continue;
		for (int j = i; j <= X2; j+= i) {
			max_prime[j] = i;
		}
	}
	int res = X2;
	assert(max_prime[X2] < X2);
	assert(X2 - max_prime[X2] >= 2);
	for (int X1 = X2; X1 > X2 - max_prime[X2]; X1--) {
		assert(X1 >= 3);
		if (max_prime[X1] == X1) continue;
		assert(X1 >= 4);
		int X0 = X1 - max_prime[X1] + 1;
		res = min(res, X0);
	}
	printf("%d\n", res);

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
int A[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	int i = 0, j = 0;
	while (j < N) {
		if (A[j] > A[i]) i++;
		j++;
	}
	printf("%d\n", i);

	return 0;
}
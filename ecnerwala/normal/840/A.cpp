#include<bits/stdc++.h>
using namespace std;
const int MAXM = 3e5;
int M;
int A[MAXM];
pair<int, int> B[MAXM];
int res[MAXM];

int main() {
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i].first);
		B[i].second = i;
	}
	sort(A, A + M);
	sort(B, B + M);
	memset(res, -1, sizeof(res));
	for (int i = 0; i < M; i++) {
		res[B[i].second] = A[M-1-i];
	}
	for (int i = 0; i < M; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}
 #include<bits/stdc++.h>
 using namespace std;
 int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	int *A = new int [N];
	for(int i = 0; i < N; i += 1) scanf("%d", A + i);
	sort(A, A + N);
	if(K == N) return printf("%d", A[N - 1]), 0;
	if(K == 0 and A[0] > 1) return printf("%d", A[0] - 1), 0;
	if(K > 0 and A[K] != A[K - 1]) return printf("%d", A[K - 1]), 0;
	printf("-1");
 }
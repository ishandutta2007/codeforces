#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
const int MAXK = 40;

int N;
int K;
int A[MAXN];

map<int, int> vals;

const int MAXQ = 40;
int Q;
int X[MAXQ];

int Y[MAXQ];

int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &Q);

	for(int i = 0; i < Q; i++) {
		scanf("%d", &X[i]);
	}

	vals[0] = 0;

	for(int i = 0; i < N; i++) {
		int a = A[i];
		for(int k = 1; k <= K; k++) {
			vals[a * k] = k;
		}
	}

	for(int q = 0; q < Q; q++) {
		int x = X[q];
		Y[q] = K + 1;
		for(int i = 0; i < N; i++) {
			for(int k = 1; k <= K; k++) {
				int v = x - A[i] * k;
				if(vals.count(v)) {
					Y[q] = min(Y[q], vals[v] + k);
				}
			}
		}

		if(Y[q] > K) Y[q] = -1;
	}

	for(int q = 0; q < Q; q++) {
		printf("%d\n", Y[q]);
	}
	return 0;
}
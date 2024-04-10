#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 200;
const int MAXM = 200;
const int MAXK = 20;

int N, M, K;
int A[MAXN][MAXM];

int R[MAXN];
int C[MAXM];

int digSum[1 << MAXK];

int go() {
	if(N > M) {
		for(int i = 0; i < N; i++) {
			for(int j = i + 1; j < N; j++) {
				swap(A[i][j], A[j][i]);
			}
		}
		swap(N, M);
	}
	//N <= M
	if(N > 2 * K) {
		R[0] = 0;
		for(int i =	1; i < N; i++) {
			int numDiff = 0;
			for(int j = 0; j < M; j++) {
				if(A[i][j] != A[i - 1][j]) {
					numDiff ++;
				}
			}
			if(numDiff <= K) {
				R[i] = R[i - 1];
			} else if(numDiff >= M - K) {
				R[i] = !R[i - 1];
			} else {
				return -1;
			}
		}
		C[0] = 0;
		for(int j = 1; j < M; j++) {
			int numDiff = 0;
			for(int i = 0; i < N; i++) {
				if(A[i][j] != A[i][j - 1]) {
					numDiff++;
				}
			}
			if(numDiff <= K) {
				C[j] = C[j - 1];
			} else if(numDiff >= N - K) {
				C[j] = !C[j - 1];
			} else {
				return -1;
			}
		}
		int res = N * M;
		for(int a = 0; a < 2; a++) {
			int numC = 0;
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(A[i][j] != a ^ R[i] ^ C[j]) numC++;
				}
			}
			if(numC < res) res = numC;
		}
		if(res > K) return -1;
		return res;
	} else if (M > 2 * K){
		R[0] = 0;
		for(int i =	1; i < N; i++) {
			int numDiff = 0;
			for(int j = 0; j < M; j++) {
				if(A[i][j] != A[i - 1][j]) {
					numDiff ++;
				}
			}
			if(numDiff <= K) {
				R[i] = R[i - 1];
			} else if(numDiff >= M - K) {
				R[i] = !R[i - 1];
			} else {
				return -1;
			}
		}

		for(int j = 0; j < M; j++) {
			C[j] = 0;
			for(int i = 0; i < N; i++) {
				C[j] += A[i][j] << i;
			}
		}

		digSum[0] = 0;
		for(int i = 1; i < (1 << N); i++) {
			digSum[i] = 1 + digSum[i & (i - 1)];
		}
		for(int i = 0; i < (1 << N); i++) {
			digSum[i] = min(digSum[i], digSum[(1 << N) - 1 - i]);
		}

		int b = 0;
		for(int i = 0; i < N; i++) b += R[i] << i;

		int k = 0;
		for(int j = 0; j < M; j++) {
			k += digSum[C[j] ^ b];
			if(k > K) break;
		}
		int res = k;
		if(res > K) return -1;
		return res;
		
		
	} else {
		// n <= 20
		for(int j = 0; j < M; j++) {
			C[j] = 0;
			for(int i = 0; i < N; i++) {
				C[j] += A[i][j] << i;
			}
		}
		digSum[0] = 0;
		for(int i = 1; i < (1 << N); i++) {
			digSum[i] = 1 + digSum[i & (i - 1)];
		}
		for(int i = 0; i < (1 << N); i++) {
			digSum[i] = min(digSum[i], digSum[(1 << N) - 1 - i]);
		}
		int res = N * M;
		for(int b = 0; b < (1 << N); b++) {
			int k = 0;
			for(int j = 0; j < M; j++) {
				k += digSum[C[j] ^ b];
				if(k > K || k >= res) break;
			}
			//cerr << b << ' ' << k << '\n';
			if(k < res) res = k;
		}
		if(res > K) return -1;
		return res;
	}
}

int main() {
	//ios_base::sync_with_stdio(0);

	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	cout  << go() << '\n';

	return 0;
}
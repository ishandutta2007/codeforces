#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e3;
const int MAXM = 1.1e3;
int N, M;
int A[MAXN][MAXM];
int B[MAXN][MAXM];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				A[i][j] ^= 1;
				A[0][j] ^= 1;
				A[i][0] ^= 1;
				A[0][0] ^= 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				cout << "No\n"; exit(0);
			}
		}
	}
	cout << "Yes" << '\n';

	return 0;
}
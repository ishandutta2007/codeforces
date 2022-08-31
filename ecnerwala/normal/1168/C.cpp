#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
int Q;

int A[MAXN];

const int MAXL = 22;
const int L = 20;
int nxtReach[MAXN][MAXL];
int nxtVal[MAXL];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < L; i++) {
		nxtVal[i] = N;
		nxtReach[N][i] = N;
	}

	for (int a = N-1; a >= 0; a--) {
		for (int i = 0; i < L; i++) {
			nxtReach[a][i] = N;
		}

		for (int i = 0; i < L; i++) {
			if (A[a] & (1 << i)) {
				for (int j = 0; j < L; j++) {
					nxtReach[a][j] = min(nxtReach[a][j], nxtReach[nxtVal[i]][j]);
				}
				nxtReach[a][i] = a;
				nxtVal[i] = a;
			}
		}
	}

	for (int q = 0; q < Q; q++) {
		int x, y; cin >> x >> y; x--, y--;

		bool good = false;
		for (int i = 0; i < L; i++) {
			if (A[y] & (1 << i)) {
				if (nxtReach[x][i] <= y) {
					good = true;
				}
			}
		}
		cout << (good ? "Shi" : "Fou") << '\n';
	}

	return 0;
}
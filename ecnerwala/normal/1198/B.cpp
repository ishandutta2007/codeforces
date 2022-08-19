#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N;
int A[MAXN];
int lastEvt[MAXN];
const int MAXQ = 2.1e5;
int Q;
int T[MAXQ];
int P[MAXQ];
int X[MAXQ];

int suffIncr[MAXQ];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> T[q];
		if (T[q] == 1) {
			cin >> P[q] >> X[q];
			P[q] --;
		} else if (T[q] == 2) {
			P[q] = -1;
			cin >> X[q];
		} else assert(false);
	}

	for (int i = 0; i < N; i++) {
		lastEvt[i] = -1;
	}

	for (int q = 0; q < Q; q++) {
		if (T[q] == 1) {
			lastEvt[P[q]] = q;
			A[P[q]] = X[q];
		}
	}
	suffIncr[Q] = 0;
	for (int q = Q-1; q >= 0; q--) {
		suffIncr[q] = suffIncr[q+1];
		if (T[q] == 2) {
			suffIncr[q] = max(suffIncr[q], X[q]);
		}
	}

	for (int i = 0; i < N; i++) {
		int v = max(A[i], suffIncr[lastEvt[i]+1]);
		cout << v << " \n"[i+1==N];
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 3e5;
const int MAXM = 3e5;
int N, M;
int K;
ll TA, TB;

ll A[MAXN];
ll B[MAXM];

ll go() {
	if (K >= N || K >= M) {
		return -1;
	}
	ll res = 0;
	for (int i = 0, j = 0; i <= K; i++) {
		while (j < M && B[j] < A[i]) {
			j++;
		}
		if (j + (K - i) >= M) return -1;
		res = max(res, B[j + (K-i)]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> TA >> TB >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] += TA + TB;
	}
	for (int j = 0; j < M; j++) {
		cin >> B[j];
		B[j] += TB;
	}

	ll res = go();
	cout << res << '\n';

	return 0;
}
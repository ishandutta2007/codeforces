#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5;
const int MAXM = 10;

int N, M;
int A[MAXM][MAXN];
int L[MAXM][MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int m = 0; m < M; m++) {
		for (int i = 0; i < N; i++) {
			cin >> A[m][i];
			A[m][i] --;
			L[m][A[m][i]] = i;
		}
	}

	ll res = 0;
	int cur = 1;
	res += cur;
	for (int i = 1; i < N; i++) {
		int x = A[0][i-1], y = A[0][i];
		bool good = true;
		for (int m = 0; m < M; m++) {
			if (L[m][y] - L[m][x] != 1) {
				good = false;
			}
		}
		if (good) {
			cur ++;
		} else {
			cur = 1;
		}
		res += cur;
	}
	cout << res << '\n';

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
ll A[MAXN];

bool makeFirstMove() {
	for (int i = 1; i < N; i++) {
		if (A[i] == A[i-1]) {
			A[i-1] --;
			return true;
		}
	}
	if (A[0] > 0) { A[0] --; return true; }
	for (int i = 1; i < N; i++) {
		if (A[i] - 1 > A[i-1]) {
			A[i] --;
			return true;
		}
	}
	return false;
}

// true if first player wins
bool go() {
	if (!makeFirstMove()) {
		return false;
	}
	sort(A, A + N);
	if (A[0] < 0) return false;
	if (unique(A, A + N) != A + N) return false;

	ll nMoves = 1;
	for (int i = 0; i < N; i++) {
		nMoves += (A[i] - i);
	}
	return (nMoves % 2 == 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);

	bool first = go();
	cout << (first ? "sjfnb" : "cslnb") << '\n';

	return 0;
}
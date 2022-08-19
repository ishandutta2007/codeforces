#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int N; cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	reverse(P.begin(), P.end());
	int A = 0, B = 0;
	for (int i : P) {
		A += i;
		if (A > B) swap(A, B);
	}
	cout << A << ' ' << B << '\n';
	return 0;
}
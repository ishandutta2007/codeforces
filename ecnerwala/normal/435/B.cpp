#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string A; cin >> A;
	int K; cin >> K;
	for (int i = 0; K && i < int(A.size()); i++) {
		int best = int(max_element(A.begin() + i, A.begin() + min(i + K + 1, int(A.size()))) - A.begin());
		while (best > i) {
			swap(A[best], A[best-1]);
			K--;
			--best;
		}
	}
	cout << A << '\n';

	return 0;
}
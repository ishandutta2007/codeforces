#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	bool roundUp = false;
	for (int i = 0; i < N; i++) {
		int A; cin >> A;
		if (A & 1) {
			if (roundUp) {
				A++;
			} else {
				A--;
			}
			roundUp = !roundUp;
		}
		cout << A / 2 << '\n';
	}

	return 0;
}
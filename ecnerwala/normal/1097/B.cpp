#include<bits/stdc++.h>
using namespace std;

int N;
int A[20];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int m = 0; m < (1 << N); m++) {
		int t = 0;
		for (int i = 0; i < N; i++) {
			if (m & (1 << i)) {
				t += A[i];
			} else {
				t -= A[i];
			}
		}
		t %= 360;
		if (t < 0) t += 360;
		if (t == 0) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}
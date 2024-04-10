#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, A, B; cin >> N >> A >> B;

	if (B == 0 && A > 0) {
		if (N == A + B + 1) {
			cout << -1 << "\n";
			return 0;
		}
		cout << 1 << " ";
		--N;
	}
	cout << 1 << " ";
	for (int i = 1; i <= B; ++i)
		cout << (1 << i) << " ";
	
	for (int i = 1; i <= A; ++i)
		cout << (1 << B) + i << " ";
	
	for (int i = A + B + 2; i <= N; ++i)
		cout << 1 << " ";
}
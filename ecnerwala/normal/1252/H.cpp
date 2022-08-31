#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int A, B; cin >> A >> B;
		if (__gcd(A,B) != 1) {
			cout << "Infinite" << '\n';
		} else {
			cout << "Finite" << '\n';
		}
	}

	return 0;
}
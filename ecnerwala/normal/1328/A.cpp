#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T; while (T--) {
		int A, B; cin >> A >> B;
		cout << (B - A % B) % B << '\n';
	}

	return 0;
}
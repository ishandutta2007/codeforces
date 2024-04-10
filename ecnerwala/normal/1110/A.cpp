#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int B, K;
	cin >> B >> K;
	bool odd = false;
	for (int i = K-1; i >= 0; i--) {
		int a; cin >> a;
		if (a % 2 == 0 || (i > 0 && (B % 2 == 0))) {
			// doesn't flip sign
		} else {
			odd = !odd;
		}
	}
	cout << (odd ? "odd" : "even") << '\n';

	return 0;
}
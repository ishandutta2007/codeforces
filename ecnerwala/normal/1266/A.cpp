#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	while (N--) {
		string X; cin >> X;
		int numEven = 0;
		int numZero = 0;
		int sum = 0;
		for (char c : X) {
			if (c == '0') numZero++;
			if ((c - '0') % 2 == 0) numEven++;
			sum += (c - '0');
		}
		if (sum % 3 == 0 && numZero >= 1 && numEven >= 2) {
			cout << "red" << '\n';
		} else {
			cout << "cyan" << '\n';
		}
	}

	return 0;
}
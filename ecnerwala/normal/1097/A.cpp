#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string A;
	cin >> A;
	string B[5];
	for (int i = 0; i < 5; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < 5; i++) {
		if (B[i][0] == A[0] || B[i][1] == A[1]) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}
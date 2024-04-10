#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		int a = int(S.find('1'));
		if (a == int(string::npos)) {
			a = N;
		}
		for (int i = 0; i < a; i++) { cout << (S[i]-'0')/2; }
		if (a < N) {
			cout << S[a];
			for (int i = a+1; i < N; i++) cout << '0';
		}
		cout << '\n';
		for (int i = 0; i < a; i++) { cout << (S[i]-'0')/2; }
		if (a < N) {
			cout << '0';
			for (int i = a+1; i < N; i++) cout << S[i];
		}
		cout << '\n';
	}

	return 0;
}
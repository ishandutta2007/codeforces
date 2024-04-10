#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string T; cin >> T;
	int na = 0;
	for (char c : T) {
		na += (c != 'a');
	}
	string S = T.substr(0, int(T.size()) - na / 2);
	string trueT = S;
	for (char c : S) {
		if (c != 'a') {
			trueT += c;
		}
	}
	if (trueT == T) {
		cout << S << '\n';
	} else {
		cout << ":(" << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string T, S;
		cin >> T;
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < T.size(); i++) {
			if (T[i] == '0') cnt0++;
			else cnt1++;
		}
		if (!cnt0 || !cnt1) {
			cout << T << endl;
			continue;
		}
		for (int i = 0; i < T.size(); i++) cout << "10";
		cout << endl;
	}
	return 0;
}
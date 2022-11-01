#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int L = -1, R = -1;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '1') {
				L = i;
				break;
			}
		for (int i = s.size() - 1; i >= 0; i--)
			if (s[i] == '1') {
				R = i;
				break;
			}
		int cnt = 0;
		if (L == -1) cout << cnt << endl;
		else {
			for (int i = L; i <= R; i++) cnt += (s[i] == '0');
			cout << cnt << endl;
		}
	}
	return 0;
}
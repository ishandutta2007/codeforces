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
		vector <int> a;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				if (cnt > 0) a.push_back(cnt);
				cnt = -1;
			}
			cnt++;
		}
		if (cnt > 0) a.push_back(cnt);
		sort(a.rbegin(), a.rend());
		int sum = 0;
		for (int i = 0; i < a.size(); i += 2)
			sum += a[i];
		cout << sum << '\n';
	}
	return 0;
}
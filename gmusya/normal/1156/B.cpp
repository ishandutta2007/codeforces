#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector <int> cnt(26);
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
		int odd = -1, even = -1;
		for (int i = 0; i < 26; i += 2)
			for (int j = 1; j < 26; j += 2) {
				if (abs(i - j) == 1) continue;
				if (!cnt[i] || !cnt[j]) continue;
				odd = j, even = i;
				break;
			}
		bool tf = true;
		int cnt_odd = 0, cnt_even = 0;
		for (int i = 0; i < 26; i += 2) cnt_even += cnt[i];
		for (int i = 1; i < 26; i += 2) cnt_odd += cnt[i];
		if (odd == -1) {
			if (cnt_even && cnt_odd) {
				cout << "No answer" << endl;
				continue;
			}
			cout << s << endl;
			continue;
		}
		for (int i = 0; i < 26; i += 2) {
			if (i == even) continue;
			while (cnt[i] > 0) {
				cout << (char)(i + 'a');
				--cnt[i];
			}
		}
		while (cnt[even] > 0) {
			cout << (char)(even + 'a');
			--cnt[even];
		}
		while (cnt[odd] > 0) {
			cout << (char)(odd + 'a');
			--cnt[odd];
		}
		for (int i = 1; i < 26; i += 2) {
			if (i == odd) continue;
			while (cnt[i] > 0) {
				cout << (char)(i + 'a');
				--cnt[i];
			}
		}
		cout << endl;
	}
	return 0;
}
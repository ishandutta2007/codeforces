#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s; 
	{
		vector <int> cnt(26);
		int ma = 0;
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - 'a']++;
			ma = max(ma, cnt[s[i] - 'a']);
		}
		if (ma >= s.size() - 1) {
			cout << "Impossible";
			return 0;
		}
	}
	for (int i = 0; i < s.size() - 1; i++) {
		string t1 = s.substr(0, i + 1);
		string t2 = s.substr(i + 1, s.size() - (i + 1));
		string t = t2 + t1;
		if (s == t) continue;
		bool tf = true;
		for (int j = 0; j < t.size(); j++) 
			if (t[j] != t[t.size() - j - 1])
				tf = false;
		if (tf) {
			cout << "1";
			return 0;
		}
	}
	cout << "2";
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iomanip>

#define fsp fixed << setprecision(9)

typedef double long dl;

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector <vector <int>> c(26);
	for (int i = 0; i < n; i++)
		c[s[i] - 'a'].push_back(i);
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		if (c[i].empty()) continue;
		int ma = 0;
		for (int d = 1; d < n; d++) {
			vector <int> cnt(26);
			for (int pos : c[i])
				cnt[s[(pos + d) % n] - 'a']++;
			int ok = 0;
			for (int i = 0; i < 26; i++)
				ok += (cnt[i] == 1);
			ma = max(ok, ma);
		}
		sum += ma;
	}
	dl a = sum, b = n;
	cout << fsp << a / b;
	return 0;
}
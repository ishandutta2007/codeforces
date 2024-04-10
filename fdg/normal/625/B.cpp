#include <iostream>
#include <vector>

using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(false);
	cin >> s >> t;
	
	int cnt = 0;
	for (int i = 0; i + t.size() <= s.size(); ++i) {
		if (s.substr(i, t.size()) == t) {
			s[i + t.size() - 1] = '';
			++cnt;
		}
	}
	cout << cnt << endl;
	return 0;
}
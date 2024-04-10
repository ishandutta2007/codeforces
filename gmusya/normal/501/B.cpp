#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	map <string, string> m;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> s >> t;
		bool tf = false;
		for (auto now : m) {
			if (now.second == s) {
				tf = true;
				m[now.first] = t;
			}
		}
		if (!tf)
			m[s] = t;
	}
	cout << m.size() << endl;
	for (auto now : m)
		cout << now.first << " " << now.second << endl;
	return 0;
}
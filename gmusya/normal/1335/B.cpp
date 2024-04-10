#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		string s;
		string t;
		for (int i = 0; i <= a - b; i++)
			t += 'a';
		while (s.size() < n) {
			s += t;
			for (int i = 1; i < b; i++)
				s += (char)(i + 'a');
		}
		s = s.substr(0, n);
		cout << s << endl;
	}
	return 0;
}
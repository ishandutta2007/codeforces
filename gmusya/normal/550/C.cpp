#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	s = "00" + s;
	for (int x = 0; x < s.size() - 2; x++)
		for (int y = x + 1; y < s.size() - 1; y++)
			for (int z = y + 1; z < s.size(); z++) {
				int num = (s[x] - '0') * 100 + (s[y] - '0') * 10 + s[z] - '0';
				if (num % 8 == 0) {
					cout << "YES" << endl;
					cout << num;
					return 0;
				}
			}
	cout << "NO";
	return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int x = 0, y = 0;
	set <pair <int, int>> se;
	se.insert({ 0, 0 });
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R')
			x++;
		if (s[i] == 'L')
			x--;
		if (s[i] == 'U')
			y++;
		if (s[i] == 'D')
			y--;
		if (se.find({ x, y }) != se.end()) {
			cout << "BUG";
			return 0;
		}
		if ((s[i] != 'R' && se.find({ x - 1, y }) != se.end()) || (s[i] != 'L' && se.find({ x + 1, y }) != se.end())) {
			cout << "BUG";
			return 0;
		}
		if ((s[i] != 'U' && se.find({ x, y - 1 }) != se.end()) || (s[i] != 'D' && se.find({ x, y + 1 }) != se.end())) {
			cout << "BUG";
			return 0;
		}
		se.insert({ x, y });
	}
	cout << "OK";
	return 0;
}
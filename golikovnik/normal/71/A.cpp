#include <iostream>
#include <string>

using namespace std;
string abbreviate(string string);

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string current;
		cin >> current;
		cout << abbreviate(current) << endl;
	}
	return 0;
}

string abbreviate(string s) {
	if (s.length() <= 10) {
		return s;
	}
	return s.at(0) + to_string(s.length() - 2) + s.at(s.length() - 1);
}
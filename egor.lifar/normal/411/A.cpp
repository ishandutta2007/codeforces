#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


string s;


int main() {
	cin >> s;
	if (s.size() < 5) {
		cout << "Too weak" << endl;
		return 0;
	}
	int n = (int)s.size();
	bool b = false;
	bool b1 = false;
	bool b2 = false;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b = true;
		}
		if (s[i] >= 'a' && s[i] <= 'z') {
			b1 = true;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {
			b2 = true;
		}
	}
	if (b && b1 && b2) {
		cout << "Correct" << endl;
	} else {
		cout << "Too weak" << endl;
	}
	return 0;
}
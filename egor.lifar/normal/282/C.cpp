#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;



string s;
string s1;


int main() {
	cin >> s >> s1;
	if (s.size() != s1.size()) {
		cout << "NO" << endl;
		return 0;
	}
	int n = s.size();
	if (n == 1) {
		if (s[0] == s1[0]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}
	bool b = true;
	bool b1 = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			b = false;
		}
		if (s1[i] == '1') {
			b1 = false;
		}
	}
	if ((!b && !b1) || (b & b1)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
    return 0;
}
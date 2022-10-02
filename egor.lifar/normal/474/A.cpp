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


char c;
string s, s1;
map<char, char> m, m1;


int main() {
	cin >> c >> s;
	string a = "qwertyuiopasdfghjkl;zxcvbnm,./";
	for (int i = 0; i < a.size(); i++) {
		if (i > 0) {
			m[a[i]] = a[i - 1];
		}
		if (i < a.size() - 1) {
			m1[a[i]] = a[i + 1];
		}
	}
	if (c == 'R') {
		for (int i = 0; i < s.size(); i++) {
			cout << m[s[i]];
		}
		cout << endl;
	} else {
		for (int i = 0; i < s.size(); i++) {
			cout << m1[s[i]];
		}
		cout << endl;
	}
    return 0;
}
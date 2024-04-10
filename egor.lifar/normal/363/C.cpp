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
 

using namespace std;


string s;


int main() {
	cin >> s;
	int l = (int)s.size();
	string s1;
	int p = 0;
	for (int i = 0; i < l; i++) {
		if (i == 0 || s[i] == s[i - 1]) {
			p++;
		} else {
			p = 1;
		}
		if (p < 3) {
			s1 += s[i];
		}
	}
	s = s1;
	l = (int)s.size();
	s1.clear();
	p = 0;
	for (int i = 0; i < l; i++) {
		int g = p;
		if (i == 0 || s[i] == s[i - 1]) {
			p++;
		} else {
			p = 1;
		}
		if (g == 2 && p == 1 && (i < l - 1 && s[i + 1] == s[i])) {
			p--;
			continue;
		} else {
			s1 += s[i];
		}
	}
	cout << s1 << endl;
 	return 0;
}
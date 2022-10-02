#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


int getnum(string a) {
	if (a == "monday") {
		return 1;
	}
	if (a == "tuesday") {
		return 2;
	}
	if (a == "wednesday") {
		return 3;
	}
	if (a == "thursday") {
		return 4;
	}
	if (a == "friday") {
		return 5;
	}
	if (a == "saturday") {
		return 6;
	}
	return 7;
}

int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main() {
	string s;
	string s1;
	cin >> s >> s1;
	int f = getnum(s) - 1;
	int f1 = getnum(s1) - 1;
	for (int st = 0; st < 7; st++) {
		int st1 = st;
		for (int i = 0; i < 11; i++) {
			if ((st1 + a[i]) % 7 == f1 && st1 == f) {
				cout << "YES" << endl;
				return 0;
			}
			st1 += a[i];
			st1 %= 7;
		}
	}
	cout << "NO" << endl;
	return 0;
}
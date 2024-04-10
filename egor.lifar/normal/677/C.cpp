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
#include <map>


using namespace std;


int Mod = 1000000007;
string s;


int getnum(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if (c >= 'A' && c <= 'Z') {
		return 10 + c - 'A';
	}
	if (c >= 'a' && c <= 'z') {
		return 36 + c - 'a';
	}
	if (c == '-') {
		return 62;
	}
	return 63;
}


int main() {
	cin >> s;
	int n = (int)s.size();
	int ans1 = 1;
	for (int i = 0; i < n; i++) {
		int f = getnum(s[i]);
		int ans = 1;
		for (int j = 0; j < 6; j++) {
			if (!(f & (1 << j))) {
				ans = (1LL * ans * 3) % Mod;
			} 
		}
		ans1 = (1LL * ans1 * ans) % Mod;
	}
	cout << ans1 << endl;
	return 0;
}
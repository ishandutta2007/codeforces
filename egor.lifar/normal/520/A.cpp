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


using namespace std;



int n;
string s;
bool b[26];


int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			b[s[i] - 'a'] = true;
		} else {
			b[s[i] - 'A'] = true;
		}
	}
	for (char c = 'a'; c <= 'z'; c++) {
		if (!b[c - 'a']) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
    return 0;
}
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


string s[8];
string s1[8];
map<char, int> m;
int sum, sum1;


int main() {
	m['q'] = m['Q'] = 9;
	m['r'] = m['R'] = 5;
	m['b'] = m['B'] = 3;
	m['n'] = m['N'] = 3;
	m['p'] = m['P'] = 1;
 	for (int i = 0; i < 8; i++) {
		cin >> s[i];
		for (int j = 0; j < 8; j++) {
			if (s[i][j] >= 'a' && s[i][j] <= 'z') {
				sum += m[s[i][j]];
			} else {
				sum1 += m[s[i][j]];
			}
		}
	}
	if (sum > sum1) {
		cout << "Black" << endl;
	} else {
		if (sum == sum1) {
			cout << "Draw" << endl;
		} else {
			cout << "White" << endl;
		}
	}
    return 0;
}
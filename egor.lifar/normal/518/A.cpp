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


string s, t;


int main() {
	cin >> s >> t;
	int n = (int)s.size();
	if (s > t) {
		cout << "No such string" << endl;
		return 0;
	}
	for (int j = n - 1; j >= 0; j--) {
		if (s[j] != 'z') {
			s[j]++;
			break;
		} else {
			s[j] = 'a';
			if (j == 0) {
				cout << "No such string" << endl;
				return 0;
			}
		}
	}
	if (s < t) {
		cout << s << endl;
	} else {
		cout << "No such string" << endl;
	}
    return 0;
}
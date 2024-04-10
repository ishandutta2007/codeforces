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


string s;


int main() {
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '9') {
			if (i != 0) {
				s[i] = '0';
			}  
		} else {
			if (s[i] >= '5') {
				s[i] = '9' - s[i] + '0';
			}
		}
	}
	cout << s << endl;
    return 0;
}
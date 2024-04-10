#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>


using namespace std;


string s;


int main() {
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string s1;
			for (int k = 0; k < i; k++) {
				s1 += s[k];
			}
			for (int k = j + 1; k < n; k++) {
				s1 += s[k];
			}
			if (s1 == "CODEFORCES") {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
    return 0;
}
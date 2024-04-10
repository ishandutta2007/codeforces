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
map<char, int> m;
bool used[200001];


int main() {
	cin >> s >> t;
	int n = (int)s.size();
	for (int i = 0; i < (int)t.size(); i++) {
		m[t[i]]++;
	}
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		if (m[s[i]]) {
			a++;
			used[i] = true;
			m[s[i]]--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				if (m[s[i] - 'a' + 'A']) {
					b++;
					m[s[i] - 'a' + 'A']--;
				}
			} else {
				if (m[s[i] - 'A' + 'a']) {
					b++;
					m[s[i] - 'A' + 'a']--;
				}
			}
		}
	}
	cout << a << ' ' << b << endl;
    return 0;
}
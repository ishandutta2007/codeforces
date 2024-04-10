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
map<char, int> m;


int main() {
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < 2 * n - 2; i++) {
		if (i % 2 == 0) {
			m[s[i]]++;
		} else {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				char c = s[i] - 'A' + 'a';
				if (m[c] == 0) {
					ans++;
				} else {
					m[c]--;
				}
			} else {
				char c = s[i] - 'a' + 'A';
				if (m[c] == 0) {
					ans++;
				} else {
					m[c]--;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
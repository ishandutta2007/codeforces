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


int n;



int main() {
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == 'U') {
				y++;
			}
			if (s[j] == 'D') {
				y--;
			}
			if (s[j] == 'R') {
				x++;
			}
			if (s[j] == 'L') {
				x--;
			}
			if (x == 0 && y == 0) {
				ans++;
			}
 		}
	}
	cout << ans << endl;
	return 0;
}
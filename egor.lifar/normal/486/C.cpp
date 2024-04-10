#include <iostream>
#include <sstream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;


int n, p;
string s;
int d[100000][2];


int main() {
	cin >> n >> p;
	cin >> s;
	bool b = true;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) {
			b = false;
		}
	}
	if (b) {
		cout << 0 << endl;
		return 0;
	}
	int l, r;
	int l1, r1;
 	for (int i = 0; i < n / 2; i++) {
 		if (s[i] != s[n - i - 1]) {
 			l = i;
 			break;
 		}
	}
	for (int i = n / 2 - 1; i >= 0; i--) {
		if (s[i] != s[n - i - 1]) {
			r = i;
			break;
		}
	}
	for (int i = (n + 1) / 2; i < n; i++) {
 		if (s[i] != s[n - i - 1]) {
 			l1 = i;
 			break;
 		}
	}
	for (int i = n - 1; i >= (n + 1) / 2; i--) {
		if (s[i] != s[n - i - 1]) {
			r1 = i;
			break;
		}
	}
	int ans = min(r - l + min(abs(p - 1 - r), abs(p - 1 - l)), r1 - l1 + min(abs(p - 1 - r1), abs(p - 1 - l1)));
	for (int i = l; i <= r; i++) {
		ans += min(min(s[i] - 'a' + 'z' - s[n - i - 1] + 1, abs(s[i] - s[n - i - 1])), s[n - i - 1] - 'a' + 'z' - s[i] + 1);
	}
	cout << ans << endl;
    return 0;
}
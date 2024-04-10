#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
int cnt[2];


int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') {
			cnt[0]++;
		} 
		if (s[i] == 'D') {
			cnt[0]--;
		}
		if (s[i] == 'L') {
			cnt[1]--;
		}
		if (s[i] == 'R') {
			cnt[1]++;
		}
	}
	if (cnt[0] % 2 == 0 && cnt[1] % 2 == 0) {
 		cout << abs(cnt[0]) / 2 + abs(cnt[1]) / 2 << endl;
	} else {
		if (abs(cnt[0]) % 2 == 1 && abs(cnt[1]) % 2 == 1) {
 			if (cnt[1] < 0) {
 				cnt[1]++;
 			} else {
 				cnt[1]--;
 			}
 			if (cnt[0] < 0) {
 				cnt[0]++;
 			} else {
 				cnt[0]--;
 			}
 			cout << 1 + abs(cnt[0]) / 2 + abs(cnt[1]) / 2 << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int k;
string s;
int d[1000000];


int main(){
	cin >> k;
	cin >> s;
	int n;
	n = (int)s.size();
	for (int i = 0; i < n; i++) {
		d[i] = s[i] - '0';
		if (i != 0) {
			d[i] += d[i - 1];
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = n - 1;
		if (d[r] - (l > 0 ? d[l - 1]: 0) < k) {
			break;
		}
		if (k == 0 && s[i] == '1') {
			continue;
		}
		while (l != r) {
			int m = (l + r) / 2;
			if (d[m] - (i > 0 ? d[i - 1]: 0) < k) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		int l1 = i;
		r = n - 1;
		while (l1 != r) {
			int m = (l1 + r + 1) / 2;
			if (d[m] - (i > 0 ? d[i - 1]: 0) < k) {
				l1 = m + 1;
			} else {
				if (d[m] - (i > 0 ? d[i - 1]: 0) == k) {
					l1 = m;
				} else {
					r = m - 1;
				}
			}
		}
		ans += 1LL * (l1 - l + 1);
	}
	cout << ans << endl;
 	return 0;
}
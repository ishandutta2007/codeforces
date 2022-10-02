#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n, m;
string s[150];
int l[150], r[150];


int main() {
	cin >> n >> m;
	int max = -1;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		l[i] = -1;
		r[i] = -1;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'W') {
				l[i] = j;
				max = i;
				break;
			}
		}
		for (int j = m - 1; j >= 0; j--) {
			if (s[i][j] == 'W') {
				r[i] = j;
				break;
			}
		}
	}
	long long ans = 0;
	int k = 0;
	for (int i = 0; i <= max; i++) {
		if (i == 0) {
			if (r[i] != -1) {
				ans += r[i];
				k = r[i];
			}
		} else {
			ans++;
			if ((i - 1) % 2 == 0) {
				if (r[i] != -1) {
					if (k < r[i]) {
						ans += r[i] - k;
						ans += r[i] - l[i];
					} else {
						ans += k - l[i]; 
					}
				}
				if (l[i] != -1) {
					k = l[i];
				}
			} else {
				if (l[i] != -1) {
					if (l[i] < k) {
						ans += k - l[i];
						ans += r[i] - l[i];
					} else {
						ans += r[i] - k;
					}
				}
				if (r[i] != -1) {
					k = r[i];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
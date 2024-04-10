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


int n, m;
int c[5001];
int b[5001];
int l[5000], r[5000], t[5000], mm[5000], d[5000];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		b[i] = 1000 * 1000 * 1000;
	}
	for (int i = 0; i < m; i++) {
		cin >> t[i];
		if (t[i] == 1) {
			cin >> l[i] >> r[i] >> d[i];
			l[i]--;
			r[i]--;
			for (int j = l[i]; j <= r[i]; j++) {
				c[j] += d[i];
			}
		} else {
			cin >> l[i] >> r[i] >> mm[i];
			l[i]--;
			r[i]--;
			for (int j = l[i]; j <= r[i]; j++) {
				b[j] = min(b[j], mm[i] - c[j]);
			}
		}
 	}
 	for (int i = 0; i < n; i++) {
 		c[i] = 0;
 	}
 	for (int i = 0; i < m; i++) {
 		if (t[i] == 2) {
 			int tt = 0;
 			for (int j = l[i]; j <= r[i]; j++) {
 				tt = max(tt, b[j] + c[j]);
 			}	
 			if (tt < mm[i]) {
 				cout << "NO" << endl;
 				return 0;
 			}
 		} else {
 			for (int j = l[i]; j <= r[i]; j++) {
				c[j] += d[i];
			}
 		}
 	}
 	cout << "YES" << endl;
 	for (int i = 0; i  < n; i++) {
 		cout << b[i] << ' ';
 	}
 	cout << endl;
	return 0;
}
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

using namespace std;


int n;
long long l[100000], r[100000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		long long r1 = r[i];
		long long l1 = l[i];
		if (r1 == 0) {
			cout << 0 << endl;
			continue;
		}
		if (l[i] == r[i]) {
			cout << l[i] << endl;
			continue;
		}
		vector<int> v;
		if (l[i] == 0) {
			v.push_back(0);
		}
		while (l[i] > 0) {
			v.push_back(l[i] % 2LL);
			l[i] /= 2;
		}
		vector<int> v1;
		if (r[i] == 0) {
			v1.push_back(0);
		}
		while (r[i] > 0) {
			v1.push_back(r[i] % 2LL);
			r[i] /= 2;
		}
		bool b = true;
		for (int j = 0; j < v1.size(); j++) {
			if (v1[j] != 1) {
				b = false;
			}
		}
		bool b1 = true;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] != 1) {
				b1 = false;
			}
		}
		if (l1 == r1) {
			cout << l1 << endl;
			continue;
		}
		if (b) {
			cout << r1 << endl;
		} else {
			if (v1.size() > v.size()) {
				long long ans = 0;
				for (int j = v1.size() - 1; j >= 1; j--) {
					ans *= 2LL;
					ans += 1LL;
				}
				cout << ans << endl;
			} else {
				// if (b1) {
				// 	cout << l1 << endl;
				// 	continue;
				// }
				int j = v.size() - 1;
				while (j >= 0 && v[j] == v1[j]) {
					j--;
				}
				while (j >= 0 && v1[j] == 0) {
					j--;
				}
				bool b2 = true;
				for (int g = j; g >= 0; g--) {
					if (v1[g] != 1) {
						b2 = false;
					} 
				}
				if (b2) {
					cout << r1 << endl;
					continue;
				}
				for (int g = 0; g <= j - 1; g++) {
					v1[g] = 1;
				}
				if (j > 0) {
 					v1[j] = 0;
 				}
				long long ans = 0;
				for (int g = v1.size() - 1; g >= 0; g--) {
					ans *= 2;
					ans += (long long)v1[g];
				}
				cout << ans << endl;
			}
		}
	}
    return 0;
}
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
 

using namespace std;


int n, m;
int a[100000];
map<int, bool> k;
int ans = 0;


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < m; j++) {
		int b;
		cin >> b;
		k[b] = true;
	}
	for (int i = 0; i < n; i++) {
		int a1 = a[i];
		int t = 2;
		while (t * t <= a1) {
			while (a1 % t == 0) {
				if (k[t]) {
					ans--;
				} else {
					ans++;
				}
				a1 /= t;
			}
			t++;
		}
		if (a1 != 1) {
			if (k[a1]) {
				ans--;
			} else {
				ans++;
			}
		}
	}
	//cout << ans << endl;
	for (int i = n - 1; i >= 0; i--) {
		int s = a[0];
		for (int j = 1; j <= i; j++) {
			s = __gcd(s, a[j]);
		}
		int a1 = s;
		int t = 2;
		int ans1 = ans;
		while (t * t <= a1) {
			while (a1 % t == 0) {
				if (k[t]) {
					ans+= (i + 1);
				} else {
					ans-= (i + 1);
				}
				a1 /= t;
			}
			t++;
		}
		if (a1 != 1) {
			if (k[a1]) {
				ans+= (i + 1);
			} else {
				ans-= (i + 1);
			}
		}
		if (ans >= ans1) {
			for (int j = 0; j <= i; j++) {
				a[j] /= s;
			}
		} else {
			ans = ans1;
		}
	}
	cout << ans << endl;
	return 0;
}
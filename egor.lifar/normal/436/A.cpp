#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;


int n, x;
int t[100000], h[100000], m[100000];
bool p[100000];

 
int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> h[i] >> m[i];
	}
	bool b = true;
	int ans = 0;
	int k = 0;
	int x1 = x;
	while(b) {
		b = false;
		int m1 = -1;
		for (int i = 0; i < n; i++) {
			if (t[i] == k && x1 >= h[i] && !p[i]) {
				m1 = max(m1, m[i]);
			}
		}
		if (m1 != -1) {
			b = true;
			for (int i = 0; i < n; i++) {
				if (t[i] == k && x1 >= h[i] && m[i] == m1 && !p[i]) {
					p[i] = true;
					break;
				}
			}
			x1 += m1;
			ans++;
		}
		k++;
		k = k % 2;
	}
	for (int i = 0; i < n; i++) {
		p[i] = false;
	}
	int ans1 = 0;
	k = 1;
	b = true;
	x1 = x;
	while(b) {
		b = false;
		int m1 = -1;
		for (int i = 0; i < n; i++) {
			if (t[i] == k && x1 >= h[i] && !p[i]) {
				m1 = max(m1, m[i]);
			}
		}
		if (m1 != -1) {
			b = true;
			for (int i = 0; i < n; i++) {
				if (t[i] == k && x1 >= h[i] && m[i] == m1 && !p[i]) {
					p[i] = true;
					break;
				}
			}
			x1 += m1;
			ans1++;
		}
		k++;
		k = k % 2;
	}
	cout << max(ans, ans1) << endl;
	return 0;
}
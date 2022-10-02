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


int n, m;
int a[140000];
int d[290000];


int main() {
	cin >> n >> m;
	int s = 1;
	for (int i = 0; i < n; i++) {
		s *= 2;
	}
	for (int i = 0; i < s; i++) {
		cin >> a[i];
		d[s + i] = a[i];
	}
	int t = s;
	int k = 0;
	for (int i = s - 1; i >= 1; i--) {
		if (t - i > t / 2) {
			t /= 2;
			k++;
			k %= 2;
		}
		if (k == 0) {
			d[i] = (d[i * 2] | d[i * 2 + 1]);
		} else {
			d[i] = (d[i * 2] ^ d[i * 2 + 1]);
		}
	}
//	cout << (1 | 6) << endl;
//	cout << d[3] << endl;
	for (int i = 0; i < m; i++) {
		int g, p;
		scanf("%d %d", &g, &p);
		g--;
		g = s + g;
		d[g] = p;
		int kk = 1;
		while (g / 2 > 0) {
			g /= 2;
			kk++;
			kk %= 2;
			if (kk == 0) {
				d[g] = (d[g * 2] | d[g * 2 + 1]);
			} else {
				d[g] = (d[g * 2] ^ d[g * 2 + 1]);
			}
		}
		cout << d[1] << endl;
	}
	return 0;
}
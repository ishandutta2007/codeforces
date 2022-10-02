#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 
using namespace std;

int main() {
	string s;
	cin >> s;
	int i = 0;
	int k = 0;
	string a, b;
	while (i < s.size() && s[i] != '|') {
		a += s[i];
		i++;
		k++;
	}
	i = s.size() - 1;
	int k1 = 0;
	while (i >= 0 && s[i] != '|') {
		b += s[i];
		i--;
		k1++;
	}
	string c;
	for (int i = b.size() - 1; i >= 0; i--) {
		c += b[i];
	}
	b = c;
	string s3;
	cin >> s3;
	int l = s3.size();
	l = l - abs(k - k1);
	if (l % 2 == 0 && l >= 0) {
		int r = 0;
		l += abs(k - k1);
		if (k < k1) {
			for (int i = 0; i < abs(k - k1); i++) {
				a += s3[i];
				r++;
			}
		} else {
			if (k > k1) {
				for (int i = r; i < abs(k - k1); i++) {
					b += s3[i];
					r++;
				}
			}
		}
		for (int i = r; i < r + (l - r) / 2; i++) {
			a += s3[i];
		}
		for (int i = r + (l - r) / 2; i < l; i++) {
			b += s3[i];
		}
		cout << a << '|' << b << endl;
	} else {
		cout << "Impossible" << endl;
	}
	return 0;
}
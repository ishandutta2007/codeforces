#include <iostream>
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
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;


typedef vector<vector<unsigned int> > mat;


mat operator * (const mat &a, const mat &b) {
	mat c(a.size(), vector<unsigned int>(a.size(), 2000000010));
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < (int)a.size(); j++) {
			for (int k = 0; k < (int)a.size(); k++) {
				c[i][k] = min(c[i][k], a[i][j] + b[j][k]);
			}
		}
	}
	return c;
}


mat pw (mat a, int n) {
	mat b(a.size(), vector<unsigned int>(a.size(), 2000000010));
	for (int i = 0; i < (int)a.size(); i++) {
		b[i][i] = 0;
	}
	while (n) {
		if (n & 1) {
			b = a * b;
		}
		a = a * a;
		n >>= 1;
	}
	return b;
}


int n, m;
unsigned int a[100], b[100];
unsigned int d[100][100];


int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	mat x(50, vector<unsigned int>(50));
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < n + 1; j++) {
			for (int k = 0; k < 50; k++) {
				d[j][k] = 2000000010;
				if (!j) {
					if (k == i) {
						d[j][k] = 0;
					}
				} else {
					if (k) {
						d[j][k] = min(d[j][k], d[j - 1][k - 1] + a[j - 1]);
					}
					if (k + 1 < 50) {
						d[j][k] = min(d[j][k], d[j - 1][k + 1] + b[j - 1]);
					}
				}
			}
		}
		for (int j = 0; j < 50; j++) {
			x[i][j] = d[n][j];
		}
	}
	cout << pw(x, m)[0][0] << endl;
	return 0;
}
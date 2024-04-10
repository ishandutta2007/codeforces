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


int n;
int a[200000], b[200000], c[200000];
int d[200000][2];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			d[i][0] = a[i];
			d[i][1] = b[i];
		} else {
			d[i][0] = max(d[i + 1][1] + a[i], d[i + 1][0] + b[i]);
			d[i][1] = max(d[i + 1][1] + b[i], d[i + 1][0] + c[i]);
		}
	}
	cout << d[0][0] << endl;
 	return 0;
}
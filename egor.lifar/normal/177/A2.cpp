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


int a[101][101];
bool b[101][101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	long long s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i][(n + 1) / 2 - 1];
		b[i][(n + 1) / 2 - 1] = true; 
	}
	for (int i = 0; i < n; i++) {
		if (b[(n + 1) / 2 - 1][i] == false) {
			s += a[(n + 1) / 2 - 1][i];
			b[(n + 1) / 2 - 1][i] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i][i] == false) {
			s += a[i][i];
			b[i][i] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i][n - i - 1] == false) {
			s += a[i][n - i - 1];
			b[i][n - i - 1] = true;
		}
	}
	cout << s << endl;
	return 0;
}
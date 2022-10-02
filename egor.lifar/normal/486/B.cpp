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
#include <map>

using namespace std;


int n, m;
int b[100][100];
int a[100][100];
int c[100], d[100];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			if (b[i][j] == 0) {
				c[i] = 1;
				d[j] = 1;
				continue; 
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == 1) {
			for (int j = 0; j < m; j++) {
				a[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (d[i] == 1) {
			for (int j = 0; j < n; j++) {
				a[j][i] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 1) {
				bool bb = true;
				for (int k = 0; k < m; k++) {
					if (a[i][k] == 1) {
						bb = false;
					}
				}
				for (int k = 0; k < n; k++) {
					if (a[k][j] == 1) {
						bb = false;
					}
				}
				if (bb) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
    return 0;
}
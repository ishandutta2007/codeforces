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
string s[1000];
int a[23][23];
int setv[23][23];
int d[5000000];
int c[23][23];


int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) { 
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
					int rek = 0;
			for (int g = 0; g < n; g++) {
					if (s[i][j] == s[g][j]) {
						setv[i][j] |= (1 << g);
						c[i][j] += a[g][j];
						rek = max(rek, a[g][j]);
					}
			}
			c[i][j] -= rek;
		}
	}
	int s = (1 << n);
	d[0] = 0;
	for (int i = 1; i < s; i++) {
		int l = 0;
		for (int j = 0; j < n; j++) {
			if (((i >> j) & 1) == 1) {
				l = j;
				break;
			}
		}
		d[i] = 1000000000;
		for (int j = 0; j < m; j++) {
			d[i] = min(d[i], d[i ^ (1 << l)] + a[l][j]);
			d[i] = min(d[i], d[i & (i ^ setv[l][j])] + c[l][j]);
		}
	}
	cout << d[s - 1] << endl;
	return 0;
}
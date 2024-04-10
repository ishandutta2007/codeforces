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


#define INF 1000000000


string s;
int d[1000010][2];
int a[1000010];


int main() {
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		a[n - i - 1] = s[i] - '0';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			d[i][j] = INF;
		}
	}
	if (a[0] == 0) {
		d[0][0] = 0;
		d[0][1] = INF;
	} else {
		d[0][0] = 1;
		d[0][1] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == 0) {
			d[i][0] = min(d[i - 1][0], d[i - 1][1] + 1);
			d[i][1] = d[i - 1][1] + 1;
		} else {
			d[i][0] = d[i - 1][0] + 1;
			d[i][1] = min(d[i - 1][0] + 1, d[i - 1][1]);
		}
	}
	cout << min(d[n - 1][0], d[n - 1][1] + 1) << endl;
	return 0;
}
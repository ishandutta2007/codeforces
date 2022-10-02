#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
int a[100001], b[100001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	long long c = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] * 2 < b[i]) {
			c--;
			continue;
		}
		if (2 > b[i]) {
			c--;
			continue;
		}
		c += 1LL * (b[i] / 2) * ((b[i] + 1) / 2);
	}
	cout << c << endl;
	return 0;
}
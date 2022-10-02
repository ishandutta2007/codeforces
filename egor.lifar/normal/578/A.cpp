#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cstring>


using namespace std;


int a, b;


int main() {
	cin >> a >> b;
	int s = a + b;
	int l = 1;
	int r = (a + b + 1) / 2;
	if (s / 2 < b) {
		cout << -1 << endl;
		return 0;
	}
	while (l != r) {
		int m = (l + r + 1) / 2;
		if (s / (m * 2) >= b) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	printf("%.10lf\n", double(s) / double(l * 2));
	return 0;
}
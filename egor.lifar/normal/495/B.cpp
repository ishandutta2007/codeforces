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
#include <assert.h>
#include <stdlib.h>


using namespace std;


int a, b;


int main() {
	cin >> a >> b;
	if (b > a) {
		cout << 0 << endl;
		return 0;
	}
	if (a == b) {
		cout << "infinity" << endl;
		return 0;
	}
	a = a - b;
	int ans = 0;
	for (int j = 1; j <= (int)sqrt(a); j++) {
		if (a % j == 0) {
			if (j > b) {
				ans++;
			}
			if (j * j != a && a / j > b) {
				ans++;
			}
		}
	}
	cout << ans << endl;
    return 0;
}
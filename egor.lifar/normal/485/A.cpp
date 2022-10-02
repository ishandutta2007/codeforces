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

using namespace std;


long long a, m;


int main() {
	cin >> a >> m;
	for (int i = 0; i < 20000000; i++) {
		a += a % m;
		if (a % m == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
    return 0;
}
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


long long n;


int main() {
	cin >> n;
	if (n % 2 == 1) {
		cout << -((n + 1) / 2) << endl;
	} else {
		cout << n / 2 << endl;
	}
    return 0;
}
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
#include <cstring>
#include <cmath>


using namespace std;


int n;

int main() {
	cin >> n;
	if (n == 1LL || n == 2LL) {
		cout << -1 << endl;
		return 0;
	}
	if (n % 2 == 1) {
		cout << (1LL + 1LL * n * n) / 2LL << ' ' << (1LL + 1LL * n * n) / 2LL - 1LL << endl;
	} else {
		cout << (2LL + 1LL * n * n / 2LL) / 2LL << ' ' << (2LL + 1LL * n * n / 2LL) / 2LL - 2LL << endl;
	}
    return 0;
}
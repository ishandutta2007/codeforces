#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


int n, m;


int main() {
	cin >> n >> m;
	if (n == 1) {
		cout << n << endl;
		return 0;
	}
	if (m - 1 >= n - m) {
		if (m - 1 == 0) {
			cout << m << endl;
			return 0;
		}
		cout << m - 1 << endl;
	} else {
		cout << m + 1 << endl;
	}
    return 0;
}
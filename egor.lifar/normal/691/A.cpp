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
#include <unordered_map>
#include <cassert>


using namespace std;


int n;


int main() {
	cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			t++;
		}
	}
	if (n == 1) {
		if (t == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} else {
		if (t == n - 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
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
#include <vector>
#include <bitset>


using namespace std;


int n;


int main() {
	cin >> n;
	if (n % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (n <= 4) {
		cout << 0 << endl;
		return 0;
	}
	cout << ((n / 2) - 1) / 2  << endl;
	return 0;
}
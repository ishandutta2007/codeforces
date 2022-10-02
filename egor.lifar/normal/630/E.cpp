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



int main() {
	long long x, y, x2, y2;
	cin >> y >> x >> y2 >> x2;
	cout << (x2 - x + 1LL) / 2LL * ((y2 - y) / 2LL) + (x2 - x + 2LL) / 2LL * ((y2 - y) / 2LL + 1LL) << endl;
	return 0;
}
//1 1 3
//1 3 1
//3 1 1
//1 2 2
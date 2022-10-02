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
	unsigned long long n;
	cin >> n;
	cout << n - n / 2 - n / 3 - n / 5 - n / 7 + n / 6 + n / 10 + n / 14 + n / 15 + n / 35 + n / 21 - n / 30 - n / 42 - n / 70 - n / 105 + n / 210 << endl;
	return 0;
}
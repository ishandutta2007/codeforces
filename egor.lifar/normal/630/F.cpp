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
	cout << (n * (n - 1) * (n - 2) * (n - 3) * (n - 4)) / 2LL / 3LL / 4LL / 5LL + (n * (n - 1) * (n - 2) * (n - 3) * (n - 4)  * (n - 5)) / 2LL / 3LL / 4LL / 5LL / 6LL + (((n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 5LL) * (n - 5)) / 6LL * (n - 6)) / 2LL / 3LL / 4LL / 7LL << endl;
	return 0;
}
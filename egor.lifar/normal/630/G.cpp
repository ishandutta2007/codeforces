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
	long long n;
	cin >> n;
	unsigned long long sum = (n >= 3 ? n * (n - 1) * (n - 2) / 6LL: 0) + 2LL * (n >= 2 ? n * (n - 1) / 2LL: 0) + n;
	unsigned long long sum1 = 6LL * (n >= 3 ? n * (n - 1) * (n - 2) / 6LL: 0) + 4LL * (n >= 2 ? n * (n - 1) / 2LL: 0) + n + 4LL * (n >= 4 ? n * (n - 1) * (n - 2) * (n - 3) / 24LL: 0) + (n >= 5 ? n * (n - 1) * (n - 2) * (n - 3) * (n - 4): 0) / 120LL;
	cout << sum * sum1 << endl;
	return 0;
}
//1 1 3
//1 3 1
//3 1 1
//1 2 2
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


int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}


int main() {
	int cnt = 2;
	for (int i = 3; i <= 10; i++) {
		cnt = cnt * i / gcd(cnt, i);
	}
	long long n;
	cin >> n;
	cout << n / (1LL * cnt) << endl;
	return 0;
}
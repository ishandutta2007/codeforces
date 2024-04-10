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
 

using namespace std;


int t;


long long nod(long long a, long long b) {
	if (a == 0LL) {
		return b;
	}
	return nod(b % a, a);
}


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long n;
		cin >> n;
		cout << ((n * 4LL) * (n + 1LL) / nod((n + 1LL), 4LL * n)) / (n + 1LL) + 1LL << endl;
	}
 	return 0;
}
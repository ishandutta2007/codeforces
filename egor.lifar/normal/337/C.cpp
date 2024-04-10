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


using namespace std;


#define M 1000000009


long long n, m, k;


long long step(long long x, int y) {
	if (y == 0) {
		return 1;
	}  else {
		if (y % 2 == 0) {
			long long g = step(x, y / 2);
			return (g * g) % M;
		} else {
			return (x * step(x, y - 1)) % M;
		}
	}
}


int main() {
	cin >> n >> m >> k;
	long long x = max(0LL, m - (n - n % k) / k * (k - 1LL) - n % k);
	cout << (((step(2, x + 1) - 2LL) * k) % M + 2LL * M + m - (x * k) % M) % M << endl;
    return 0;
}
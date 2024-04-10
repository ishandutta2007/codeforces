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


int a, b, c, l;


long long bad(int a, int b, int c) {
	long long res = 0;
	for (int i = 0; i <= l; i++) {
		int newa = a + i;
		int f = l - i;
		int sum = b + c;
		if (sum > newa) {
			continue;
		}
		f = min(f, newa - sum);
		res += 1LL * (f + 2) * (f + 1) / 2LL;
	}
	return res;
}


int main() {
  	cin >> a >> b >> c >> l;
  	long long ans = 1LL * (l + 1) * (l + 2) * (l + 3) / 6LL;
  	ans -= bad(a, b, c);
  	ans -= bad(b, a, c);
  	ans -= bad(c, a, b);
  	cout << ans << endl;
    return 0;
}
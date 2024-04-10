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


using namespace std;



long long a, b;


int main() {
	cin >> a >> b;
	long long k = 0;
	while (a != 0LL && b != 0LL) {
		k += max(a, b) / min(a, b);
		if (a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}
	cout << k << endl;
	return 0;
}
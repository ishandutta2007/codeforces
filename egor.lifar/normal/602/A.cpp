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

using namespace std;


int n, bx;


int main() {
	cin >> n >> bx;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ans *= 1LL * bx;
		ans += a;
	}
	cin >> n >> bx;
	long long ans1 = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ans1 *= 1LL * bx;
		ans1 += a;
	}
	if (ans == ans1) {
		cout << "=" << endl;
	} else {
		if (ans > ans1) {
			cout << ">" << endl;
		} else {
			cout << "<" << endl;
		}
	}
	return 0;
}
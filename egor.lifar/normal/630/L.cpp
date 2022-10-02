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
	string s;
	cin >> s;
	if ((int)s.size() != 5) {
		return 1;
	}
	long long a = ((((s[0] - '0') * 10LL + (s[2] - '0')) * 10LL + (s[4] - '0')) * 10LL + (s[3] - '0')) * 10LL + (s[1] - '0');
	long long b = 1;
	for (int j = 0; j < 5; j++) {
		b = (1LL * b * a) % 100000LL;
	}
	if (b < 10000) {
	 	int b1 = b;
	 	int cnt = 0;
	 	while (b1 > 0) {
	 		b1 /= 10;
	 		cnt++;
	 	}
	 	for (int i = 0; i < 4 - cnt; i++) {
	 		cout << 0;
	 	}
	}
	cout << b << endl;
	return 0;
}
//1 1 3
//1 3 1
//3 1 1
//1 2 2
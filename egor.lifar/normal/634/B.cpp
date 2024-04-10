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


long long s, x;
long long d[65][2];


int main() {
	cin >> s >> x;
	long long ans = 0;
	if (s == x) {
		ans -= 2LL;
	}
	vector<int> v, v1;
	for (int i = 0; i < 64; i++) {
		v.push_back(s % 2LL);
		v1.push_back(x % 2LL);
		s /= 2LL;
		x /= 2LL;
		//cout << v[i];
	}
	//cout << endl;
	d[0][0] = 1;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 2; j++) {
			for (int g = 0; g < 2; g++) {
				for (int h = 0; h < 2; h++) {
					if ((g ^ h) == v1[i]) {
						if ((j + g + h) % 2 == v[i]) {
							d[i + 1][(j + g + h) / 2] += d[i][j];
						}
					}
				}
			}
		}
	}
	ans += d[64][0];
	cout << ans << endl;
	return 0;
}
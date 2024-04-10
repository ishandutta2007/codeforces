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


int x;
string a, b;
int d[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main() {
	cin >> x >> a >> b;
	if (b == "month") {
		int ans = 0;
		for (int i = 0; i < 12; i++) {
			if (d[i] >= x) {
				ans++;
			}
		}
		cout << ans << endl;
		return 0;
	}
	int g = 5;
	int ans = 0;
	for (int i = 0; i < 366; i++) {
		if (g == x) {
			ans++;
		}
		g++;
		g = g % 7;
		if (g == 0) {
			g = 7;
		}
	}
	cout << ans << endl;
	return 0;
}
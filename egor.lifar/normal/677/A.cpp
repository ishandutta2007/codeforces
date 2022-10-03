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
#include <map>


using namespace std;


int n, h;
int a[1001];


int main() {
	cin >> n >> h;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > h) {
			ans += 2;
		} else {
			ans += 1;
		}
	}
	cout << ans << endl;
	return 0;
}
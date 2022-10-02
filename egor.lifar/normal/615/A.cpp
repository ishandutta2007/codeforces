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



int n, m;
bool good[1001];


int main () {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			int y;
			cin >> y;
			y--;
			good[y] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!good[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
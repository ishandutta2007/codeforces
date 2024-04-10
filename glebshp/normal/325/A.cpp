#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const long long inf = (long long) 1e18;

int main() {
	int n;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> n;
	long long minX = inf, maxX = -inf, minY = inf, maxY = -inf;
	long long xc1, yc1, xc2, yc2;
	long long sq = 0;

	for (int i = 0; i < n; i++) {
		cin >> xc1 >> yc1 >> xc2 >> yc2;
		sq += abs((xc2 - xc1) * (yc2 - yc1));
		minX = min(minX, min(xc1, xc2));
		maxX = max(maxX, max(xc1, xc2));
		minY = min(minY, min(yc1, yc2));
		maxY = max(maxY, max(yc1, yc2));
	}

	if (((maxX - minX) == (maxY - minY)) && (maxX - minX) * (maxY - minY) == sq) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

    return 0;
}
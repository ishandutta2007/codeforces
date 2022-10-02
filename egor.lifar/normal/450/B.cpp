#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


#define INF 1000000007


int x, y, n;


int f[10];


int main() {
	cin >> x >> y >> n;
	f[1] = x;
	f[2] = y;
	f[3] = y - x;
	f[4] = -x;
	f[5] = -y;
	f[6] = -y + x;
	n = n % 6;
	if (n == 0) {
		n += 6;
	}
	cout << (f[n] % INF + INF) % INF << endl;
	return 0;
}
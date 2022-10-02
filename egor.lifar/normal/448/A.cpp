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


int n;
int k1, k2, k3;
int m1, m2, m3;


int main() {
	cin >> k1 >> k2 >> k3 >> m1 >> m2 >> m3 >> n;
	int s = (k1 + k2 + k3 + 4) / 5 + (m1 + m2 + m3 + 9) / 10;
	if (s <= n) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int n, m;


int main() {
	cin >> n >> m;
	cout << n + m - 1 << endl;
	for (int i = 0; i < m; i++) {
		cout << 1 << ' ' << i + 1 << endl;
	}
	for (int i = 1; i < n; i++) {
		cout << i + 1 << ' ' << 1 << endl;
	}
    return 0;
}
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
#include <unordered_map>


using namespace std;


int n, m;


int main() {
	cin >> n >> m;
	if (n * m == 1) {
		cout << 1 << endl;
		return 0;
	}
	printf("%.10lf\n", 1.0 / double(n) + (double(n - 1) / double(n)) * (double(m - 1) / double(n * m - 1)));
    return 0;
}
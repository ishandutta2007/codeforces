#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <complex>


using namespace std;

int k, r;

int main() {
	cin >> k >> r;
	for (int i = 1; i <= 10; i++) {
		if ((k * i) % 10 == 0 || (k * i) % 10 == r) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
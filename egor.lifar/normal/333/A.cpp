#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


long long n;


int main() {
	cin >> n;
	long long s = 3;
	while (n % s == 0) {
		s *= 3;
	}
	cout << (n + s - 1) / s << endl;
	return 0;
}
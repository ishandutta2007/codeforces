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
 

using namespace std;


int n;


int main(){
	cin >> n;
	for (int j = 1; j <= 200000; j++) {
		int sum = 4 * j;
		if (sum > n) {
			break;
		}
		int f = (n - sum) / 3;
		if (f <= j && f * 3 + sum == n) {
			for (int g = 0; g < j - f; g++) {
				cout << 4;
			}
			for (int g = 0; g < f; g++) {
				cout << 7;
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
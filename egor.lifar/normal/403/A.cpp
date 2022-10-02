#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 

using namespace std;


int t, n, p;


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> p;
		int k = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (k >= 2 * n + p) {
					break;
				}
				k++;
				cout << i + 1 << ' ' << j + 1 << endl;
			}
		}
	}
	return 0;
}
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


int n, k;



int main() {
	cin >> n >> k;
	int s = k;
	if (s > (n * n + 1) / 2) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 0 && s > 0) {
				cout << "L";
				s--;
			} else {
				cout << "S";
			}
		}
		cout << endl;
	}
 	return 0;
}
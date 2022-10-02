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
#include <unordered_set>
#include <set>
 

using namespace std;


int t;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		if (n % 2 == 0) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}
 	return 0;
}
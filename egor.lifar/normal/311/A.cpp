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


int n, k;


int main() {
	cin >> n >> k;
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			s++;
		}
	}
	if (s <= k) {
		cout << "no solution" << endl; 
	} else {
		for (int i = 0; i < n; i++) {
			cout << 0 << ' ' << i << endl;
		}
	}
	return 0;
}
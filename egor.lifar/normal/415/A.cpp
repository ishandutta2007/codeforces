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
 

using namespace std;


int n, k;


map<int, int> m;


int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		a--;
		for (int j = a; j < n; j++) {
			if (m.find(j) == m.end()) {
				m[j] = a + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << m[i] << ' ';
	}
	cout << endl;
	return 0;
}
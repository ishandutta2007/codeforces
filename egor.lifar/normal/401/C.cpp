#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, m;


int main() {
	cin >> m >> n;
	if (m > n + 1) {
		cout << -1 << endl;
		return 0;
	}
	if (n > (m + 1) * 2) {
		cout << -1 << endl;
		return 0;
	}
	if (n > m * 2 + 1) {
		cout << 11;
		n-= 2;
	} 
	if (n > m * 2) {
		cout << 1;
		n--;
	}
    for (int i = 0; i < m; i++) {
		cout << 0;
		if (n >= m - i && n >= 2) {
			cout << 11;
			n-= 2;
		} else {
			if (n > 0) {
				n--;
				cout << 1;
			}
		}
	}
	cout << endl;
	return 0;
}
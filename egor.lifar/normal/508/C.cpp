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
#include <assert.h>


using namespace std;


int m, t, r;
int w[300];
bool b[5000];


int main() {
	cin >> m >> t >> r;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> w[i];
		int k = 0;
		for (int j = w[i] - 1; j >= w[i] - t; j--) {
			k += b[j + 2500];
		}
		if (k < r) {
			for (int j = w[i] - 1; j >= w[i] - t; j--) {
				if (k < r && !b[j + 2500]) { 
					b[j + 2500] = 1;
					k++;
					ans++;
				}
			}
			if (k < r) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
  	return 0; 
}
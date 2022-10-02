#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>


using namespace std;


int n;
int x[2000], y[2000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i]; 
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((x[j] - x[i]) * (y[k] - y[i]) != (y[j] - y[i]) * (x[k] - x[i])) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}
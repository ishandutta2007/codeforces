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
#include <queue>
#include <unordered_map>


using namespace std;


int n, k;


int main() {
	cin >> n >> k;
	if (3 * k > n) {
		cout << -1 << endl;
		return 0;
	}
	int i = 0;
	while (i < n) {
		if (i >= 2 * k && i < 3 * k) {
			for (int j = 0; j < k - 1; j++) {
				printf("%d ", j + 2);
			}
			printf("%d ", 1);
			i += k;
			continue;
		}
		int t = 0;
		while (i < n && t < k) {
			t++;
			printf("%d ", t);
			i++;
		}
  	}
  	cout << endl;
    return 0;
}
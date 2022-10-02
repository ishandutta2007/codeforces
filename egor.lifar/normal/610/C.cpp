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
#include <vector>
#include <bitset>


using namespace std;


int k;
bool a[1024][1024];


int main() {
	cin >> k;
	for (int i = 0; i <= k; i++) {
		if (i == 0) {
			a[0][0] = 1;
			continue;
		}
		int s = (1 << (i - 1));
		for (int j = s; j < 2 * s; j++) {
			for (int k = 0; k < s; k++) {
				a[j][k] = a[j - s][k];
			}
		}
		for (int j = 0; j < s; j++) {
			for (int k = s; k < 2 * s; k++) {
				a[j][k] = a[j][k - s];
			}
		}
		for (int j = s; j < 2 * s; j++) {
			for (int k = s; k < 2 * s; k++) {
				a[j][k] = 1 - a[j - s][k - s];
			}
		}
	}
	int s = (1 << k);
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (a[i][j]) {
				printf("+");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
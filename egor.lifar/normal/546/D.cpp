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


int d[5000001];
int used[5000001];


int main() {
	for (int j = 2; j <= 5000000; j++) {
		if (used[j] == 0) {
			used[j] = 1;
			for (int g = j + j; g <= 5000000; g += j) {
				int k = g;
				int f = 0;
				while (k % j == 0) {
					k /= j;
					f++;
				}
				used[g]+= f;
			}
		}
		//cout << used[j] << endl;
		d[j] = d[j - 1] + used[j];
	}
	int t;
	cin >> t;
	//cout << d[6] << endl;
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", d[a] - d[b]);
	}
	return 0;
}
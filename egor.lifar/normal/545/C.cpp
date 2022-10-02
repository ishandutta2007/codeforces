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


int n;
int x[100001];
int h[100001];


int main() {
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &h[i]);
	}
	int t = -2000000001;
	for (int i = 0; i < n; i++) {
		if (x[i] - h[i] > t) {
			k++;
			t = x[i];
		} else {
			if (x[i] + h[i] < (i == n - 1 ? 2000000001: x[i + 1])) {
				t = x[i] + h[i];
				k++;
			}
		}
		t = max(t, x[i]);
	}
	cout << k << endl;
	return 0;
}
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


int n;
int a[200000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		while (a[i] % 2 == 0) {
			a[i] /= 2;
		}
		while (a[i] % 3 == 0) {
			a[i] /= 3;
		}
		if (i != 0) {
			if (a[i] != a[i - 1]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
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
int a[200000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		a[i] -= i;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			cout << ":(" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
 	return 0;
}
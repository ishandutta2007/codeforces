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
int a[100001];
int b[100001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			b[i] = a[i];
		} else {
			b[i] = a[i] + a[i + 1];
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
	cout << endl;
	return 0;
}
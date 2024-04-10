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


int n;
int a[100000];
int b[1000001];


int main() {
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = k + 1; j <= k + a[i]; j++) {
			b[j] = i + 1;
		}
		k += a[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l;
		cin >> l;
		cout << b[l] << endl;
	}
    return 0;
}
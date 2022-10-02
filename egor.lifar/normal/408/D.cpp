#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 

using namespace std;


int n;
int p[3001];
long long d[3001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		d[i + 1] = 2 * d[i] + 2 - d[p[i]];
		d[i] = d[i] % 1000000007;
		d[i + 1] = d[i + 1] % 1000000007;
	}
	cout << (1000000007 + d[n]) % 1000000007 << endl;
	return 0;
}
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


int p, n;
int x[100000];
int ans = -1;
bool b[100000];


int main() {
	cin >> p >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		if (b[x[i] % p] == true) {
			ans = i + 1;
			break;
		} else {
			b[x[i] % p] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
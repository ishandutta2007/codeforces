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
int p[100000], q[100000];
int ans = 0;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> q[i];
		if (q[i] - p[i] >= 2) {
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}
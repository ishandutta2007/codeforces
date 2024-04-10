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


int n, m;
int a[100000];
int ans = 0;
int s = 0;



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (s <= (a[i] + m - 1) / m) {
			s = (a[i] + m - 1) / m;
			ans = i;
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
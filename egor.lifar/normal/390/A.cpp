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
int k[102], k1[102];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		k[a]++;
		k1[b]++;
	}
	int sum = 200;
	int ans = 0, ans1 = 0;
	for (int i = 0; i <= 100; i++) {
		if (k[i] > 0) {
			ans++;
		}
		if (k1[i] > 0) {
			ans1++;
		}
	}
	sum = min(ans, ans1);
	cout << sum << endl;
	return 0;
}
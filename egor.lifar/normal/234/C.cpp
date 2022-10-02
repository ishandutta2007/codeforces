#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;


int n, t[100000];
int cold, hot;
int ans = 1000000000;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < n; i++) {
		if (t[i] <= 0) {
			cold++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == 0 && t[i] > 0) {
			ans = min(ans, cold + hot + 1);
		} else {
			ans = min(ans, cold + hot);
		}
		if (t[i] >= 0) {
			hot++;
		} 
		if (t[i] <= 0) {
			cold--;
		}
	}
	cout << ans << endl;
	return 0;
}
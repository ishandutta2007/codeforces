#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>

#define ll long long int
#define ii for (int i = 0; i < n; i++)

using namespace std;

bool proverka(int n) {
	vector <bool> used(10);
	while (n > 0) {
		if (used[n % 10]) return false;
		else (used[n % 10]) = true;
		n /= 10;
	}
	return true;
}

int l, r;

int main() {
	cin >> l >> r;
	int ans = 0;
	bool tf = false;
	for (int i = l; i <= r; i++) {
		if (proverka(i)) {
			tf = true;
			ans = i;
		}
	}
	if (tf) cout << ans;
	else cout << "-1";
	return 0;
}
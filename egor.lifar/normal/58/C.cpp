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
int ans = 1000000000;



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i < (n + 1) / 2 && a[i] - i > 0) {
			b[a[i] - i]++;
		} else {
			if (a[i] - (n - i - 1) > 0) {
				b[a[i] - (n - i - 1)]++;
			}
		}
	}
	for (int i = 1; i <= 100000; i++) {
		int s = n - b[i];
		ans = min(ans, s);
	}
	cout << ans << endl;
	return 0;
}
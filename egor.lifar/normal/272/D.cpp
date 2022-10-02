#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>


using namespace std;


int n;
long long m;
pair<int, int> a[300000];
int ans = 1;


void funct(int a, int b) {
	for (int i = 2; i <= a; i++) {
		int x = i;
		while (b && x % 2 == 0) {
			x = x / 2;
			b--;
		}
		ans = (1LL * ans * x) % m;
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i + n].first;
		a[i + n].second = i + 1;
	}
	cin >> m;
	sort(a, a + 2 * n);
	int j = 0, c = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (i != j && a[i] == a[i - 1]) {
			c++;
		}
		if (i == 2 * n - 1 || a[i + 1].first != a[i].first) {
			funct(i - j + 1, c);
			j = i + 1;
			c = 0;
		}
	}
	cout << ans << endl;
    return 0;   
}
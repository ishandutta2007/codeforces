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
vector<int> p;


int main() {
	cin >> n;	
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		bool b = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				b = false;
			}
		}
		if (b) {
			int h = i;
			int g = 0;
			while (n >= h) {
				g++;
				h *= i;
			}
			ans += g;
			p.push_back(i);
		}
	}
	cout << ans << endl;
	for (int i = 0; i < (int)p.size(); i++) {
		int h = p[i];
		while (h <= n) {
			printf("%d ", h);
			h *= p[i];
		}
	}
	cout << endl;
	return 0;
}
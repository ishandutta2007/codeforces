#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>


using namespace std;


int n;
int d[2000001];
int c[2000001];
int tt[7];


int main() {
	cin >> n;
	d[0] = 0;
	c[0] = -1;
	int n1 = n;
	int t = 0;
	while (n1 > 0) {
		n1 /= 10;
		t++;
	}
	tt[0] = 1;
	for (int j = 1; j <= 6; j++) {
		tt[j] = tt[j - 1] * 10;
	}
	t = min(t, 6);
	if (n == 1000000) {
		cout << 1 << endl;
		cout << 1000000 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1000001;
		c[i] = 0;
	//	cout << (1 << t) << endl;
		vector<int> v;
		v.resize(6);
		int ans = 0;
		for (int g = 1; g < (1 << t); g++) {
			int cc = 1;
			for (int j = 0; j < (int)v.size(); j++) {
				if (v[j] == 1) {
					ans -= tt[j];
				}
				v[j] += 1;
				cc = 0;
				if (v[j] >= 2) {
					v[j] = 0;
					cc = 1;
				}
				if (v[j] == 1) {
					ans += tt[j];
				}
				if (cc == 0) {
					break;
				}
			}
			if (ans > i) {
				break;
			}
		//	cout << t << endl;
			if (d[i] > d[i - ans] + 1) {
				d[i] = d[i - ans] + 1;
				c[i] = ans;
			}
		} 
	}
//	return 0;
	cout << d[n] << endl;
	while (n > 0) {
		printf("%d ", c[n]);
		int gg = c[n];
		n -= gg;
	}
	cout << endl;
    return 0;
}
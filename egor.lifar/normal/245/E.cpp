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
 

using namespace std;


string s;
int a[100000];
int b[100000];



int main() {
	cin >> s;
	int n = (int)s.size();
	int ans = 1;
	for (int i = 0; i < n; i++) {
		a[i] = (i > 0 ? a[i - 1]: 0);
		b[i] = (i > 0 ? b[i - 1]: 0);
		if (s[i] == '+') {
			a[i]++;
		}
		if (s[i] == '-') {
			b[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int g = a[j] - (i > 0 ? a[i - 1]: 0);
			int g1 = b[j] - (i > 0 ? b[i - 1]: 0);
			ans = max(ans, abs(g - g1));
		}
	}
	cout << ans << endl;
	return 0;
}
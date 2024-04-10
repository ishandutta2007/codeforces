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
int a[1000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int k = 1;
	int s = 0;
	int s1 = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || (i > 0 && a[i] == a[i - 1])) {
			s1++;
		} else {
			k++;
			s = max(s, s1);
			s1 = 1;
		}
	}
	if ((n >= 2 && a[n - 1] == a[n - 2]) || n == 1) {
		s = max(s, s1);
		s1 = 1;
	}
	cout << s << ' ' << k << endl;
    return 0;
}
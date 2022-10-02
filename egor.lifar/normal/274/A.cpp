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


int n, k;
int a[100000];
set<int> s;


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] % k != 0) {
			s.insert(a[i]);
		} else {
			if (s.find(a[i] / k) == s.end()) {
				s.insert(a[i]);
			}
		}
	}
	cout << s.size() << endl;
    return 0;
}
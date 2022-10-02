#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, x, a[100000];
int s = 0;


int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	s = abs(s);
	cout << (s + x - 1) / x << endl;
	return 0;
}
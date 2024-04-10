#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>


using namespace std;


int n;
string s;
int m;
int c[300001];


int main() {
	cin >> s;
	n = (int)s.size();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		c[k - 1]++;
		c[n - k + 1]--;
	}
	int t = 0;
	for (int i = 0; i < n / 2; i++) {
		t += c[i];
		if (t % 2 == 1) {
			swap(s[i], s[n - i - 1]);
		}
	}
	cout << s << endl;
	return 0;
}
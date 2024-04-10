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


string s;
int n;
bool b[4];


int main() {
	cin >> s;
	n = s.size();
	vector<int> v;
	int k = 0;
	int a[4];
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			k++;
			continue;
		}
		if (s[i] == '1' && !b[0]) {
			b[0] = true;
			a[0] = 1;
			continue;
		}
		if (s[i] == '6' && !b[1]) {
			b[1] = true;
			a[1] = 6;
			continue;
		}
		if (s[i] == '8' && !b[2]) {
			b[2] = true;
			a[2] = 8;
			continue;
		}
		if (s[i] == '9' && !b[3]) {
			b[3] = true;
			a[3] = 9;
			continue;
		}
		v.push_back(s[i] - '0');
	}
	do {
		int s = 0;
		for (int i = 0; i < v.size(); i++) {
			s *= 10;
			s += v[i];
			s %= 7;
		}
		for (int i = 0; i < 4; i++) {
			s *= 10;
			s += a[i];
			s %= 7;
		}
		for (int i = 0; i < k; i++) {
			s *= 10;
			s %= 7;
		}
		if (s == 0) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			for (int i = 0; i < 4; i++) {
				cout << a[i];
			}
			for (int i = 0; i < k; i++) {
				cout << 0;
			}
			cout << endl;
			return 0;
		}
	} while(next_permutation(a, a + 4));
	return 0;
}
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n, x, y, l;
int a[100000];
map<int, bool> m;
bool b, c;

//
int main() {
	cin >> n >> l >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= x && m[a[i] - x]) {
			b = true;
		}
		if (a[i] >= y && m[a[i] - y]) {
			c = true;
		}
	}
	if (b && c) {
		cout << 0 << endl;
		return 0;
	}
	if (b) {
		cout << 1 << endl;
		cout << l - y << endl;
		return 0;
	}
	if (c) {
		cout << 1 << endl;
		cout << l - x << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= x) {
			if (m[a[i] - x - y]) {
				cout << 1 << endl;
				cout << a[i] - x << endl;
				return 0;
			} 
			if (m[y + (a[i] - x)]) {
				cout << 1 << endl;
				cout << a[i] - x << endl;
				return 0;
			} 
		}
		if (a[i] >= y) {
			if (m[(a[i] - y) - x]) {
				cout << 1 << endl;
				cout << a[i] - y << endl;
				return 0;
			}
			if (m[abs(x + (a[i] - y))]) {
				cout << 1 << endl;
				cout << a[i] - y << endl;
				return 0;
			}
		}
		if (a[i] + x <= l) {
			if (m[(a[i] + x) - y]) {
				cout << 1 << endl;
				cout << a[i] + x << endl;
				return 0;
			} 
			if (m[y + (a[i] + x)]) {
				cout << 1 << endl;
				cout << a[i] + x << endl;
				return 0;
			} 
		}
		if (a[i] + y <= l) {
			if (m[(a[i] + y) - x]) {
				cout << 1 << endl;
				cout << a[i] + y << endl;
				return 0;
			}
			if (m[abs(x + (a[i] + y))]) {
				cout << 1 << endl;
				cout << a[i] + y << endl;
				return 0;
			}
		}
	}
	cout << 2 << endl;
	cout << l - x <<  ' ' << l - y << endl;
	return 0;
}
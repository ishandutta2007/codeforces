#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;



int a1, a2, a3, a4;
string s;


int main() {
	cin >> a1 >> a2 >> a3 >> a4;
	if (abs(a3 - a4) > 1) {
		cout << -1 << endl;
		return 0;
	}
	if (a3 == a4) {
		if (a3 + 1 <= a1 && a3 <= a2) {
			for (int i = 0; i < a3; i++) {
				s += '4';
				s += '7';
			}
			s += '4';
			a1 -= a3 + 1;
			a2 -= a3;
		} else {
			if (a4 + 1 <= a2 && a4 <= a1) {
				for (int i = 0; i < a3; i++) {
					s += '7';
					s += '4';
				}
				s += '7';
				a2 -= a4 + 1;
				a1 -= a4;
			} else {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	if (a3 > a4) {
		if (a3 <= a1 && a3 <= a2) {
			for (int i = 0; i < a3; i++) {
				s += '4';
				s += '7';
			}
			a1 -= a3;
			a2 -= a3;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	if (a3 < a4) {
		if (a4 <= a1 && a4 <= a2) {
			for (int i = 0; i < a4; i++) {
				s += '7';
				s += '4';
			}
			a1 -= a4;
			a2 -= a4;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	int k;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '7') {
			k = i;
			break;
		}
	}
	bool b = true;
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		if (s[i] == '4' && b) {
			b = false;
			for (int j = 0; j < a1; j++) {
				cout << '4';
			}
		}
		if (k == i) {
			for (int j = 0; j < a2; j++) {
				cout << '7';
			}
		}
	}
	cout << endl;
	return 0;
}
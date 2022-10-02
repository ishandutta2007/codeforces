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
#include <unordered_map>
#include <cassert>


using namespace std;


int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	int l = 0;
	int r = n - 1;
	while (s[l] == '0' && l < n - 1 && s[l + 1] != '.') {
		l++;
	}
	bool g = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {
			g = 1;
		}
	}
	if (g) {
	 	while (s[r] == '0' && r > 0) {
			r--;
		}
	}
	if (s[r] == '.') {
		r--;
	}
	string a;
	if (s[l]== '.') {
		a += '0';
	}
	bool b = 0;
	for (int i = l; i <= r; i++) {
		a += s[i];
		if (s[i] == '.') {
			b = 1;
		} 
	}
	r = (int)a.size();
	if (!b) {
		printf("%c", a[0]);
		string s1;
		bool bad = 0;
		for (int i = 1; i < r; i++) {
			if (i == 1) {
				s1 += '.';
			}
			s1 += a[i];
			if (a[i] != '0') {
				bad = 1;
			}
		}
		while (s1.back() == '0') {
			s1.pop_back();
		}
		if (bad) {
			cout << s1;
		}
		if (r != 1) {
			printf("E%d", r - 1);
		}
		printf("\n");
	} else {
		if (a[0] != '0') {
			printf("%c", a[0]);
			int pos = -1;
			for (int i = 1; i < r; i++) {
				if (i == 1) {
					printf(".");
				}
				if (a[i] != '.') {
					printf("%c", a[i]);
				} else {
					pos = i;
				}
			}
			if (pos - 1 != 0) {
				printf("E%d", pos - 1);
			}
			printf("\n");
		} else {
			int pos = -1;
			bool bb = 0;
			//cout << "opa" << endl;
			string s1;
			int cnt = 0;
			for (int i = 2; i < r; i++) {
				if (a[i] != '0') {
					if (!bb) {
						printf("%c", a[i]);
						pos = i;
					}
					bb = 1;
				}
				if (bb) {
					cnt++;
				}
				if (bb && cnt >= 2) {
					s1 += a[i];
				}
			}
			if ((int)s1.size() != 0) {
				cout << '.' << s1;
			}
			if (r != 1) {
				printf("E%d", -pos + 1);
			}
			printf("\n");
		}
	}
	return 0;
}
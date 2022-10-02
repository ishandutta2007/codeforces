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
#include <stdlib.h>


using namespace std;


string s;
int n;
int a[100000];
multiset<int> r;


int main() {
	cin >> s;
	n = (int)s.size();
	int k = 0;
	int k1 = 0;
	int k2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			k++;
		}
		if (s[i] == ')') {
			k1++;
		}
		if (s[i] == '#') {
			k2++;
		}
	}
	if (k < k1 + k2) {
		printf("%d\n", -1);
		return 0;
	}
	int p = k - k1 - k2;
	for (int i = 0; i < k2; i++) {
		a[i] = 1;
	}
	int t1 = 0;
	int t2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			t1++;
		}
		if (s[i] == ')') {
			t2++;
		}
		if (s[i] == '#') {
			t2++;
			if (t2 > t1) {
				cout << -1 << endl;
				return 0;
			}
			//cout << t2 << endl;
		}
		if (t2 > t1) {
			cout << -1 << endl;
			return 0;
		}
		r.insert(t1 - t2);
	}
	int g = 0;
	int j = 0;
	int t = 0;
	t1 = 0;
	t2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			t1++;
		}
		if (s[i] == ')') {
			t2++;
		}
		if (s[i] == '#') {
			t2++;
			t++;
			if (*(r.begin()) > g) {
				g = *(r.begin());
				j = t - 1;
			}
			//cout << t2 << endl;
		}
		r.erase(r.find(t1 - t2));
	}
	if (p > g) {
		cout << -1 << endl;
		return 0;
	}
	//cout << j << endl;
	a[j] += min(g, p);
	for (int i = 0; i < k2; i++) {
		cout << a[i] << endl;
	}
    return 0;
}
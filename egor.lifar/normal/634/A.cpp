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
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;


int n;
int a[200032], b[200032];


int main() {
	cin >> n;
	vector<int> v;
	bool t = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			t = 0;
		}
		if (!t && a[i]) {
			v.push_back(a[i]);
		}
	}
	t = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			t = 0;
		}
		if (t && a[i]) {
			v.push_back(a[i]);
		}
	}
	vector<int> v1;
	t = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (b[i] == 1) {
			t = 0;
		}
		if (!t && b[i]) {
			v1.push_back(b[i]);
		}
	}
	t = 1;
	for (int i = 0; i < n; i++) {
		if (b[i] == 1) {
			t = 0;
		}
		if (t && b[i]) {
			v1.push_back(b[i]);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (v[i] != v1[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
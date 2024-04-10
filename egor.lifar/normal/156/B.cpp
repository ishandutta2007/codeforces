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


int n;
int m;
int a[100001];
vector<int> v[100001];
int f[100001];
int f1[100001];



bool can[100000];


int main() {
	cin >> n >> m;
	int k = 0;
	int k1 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > 0) {
			k++;
			f[a[i]]++;
		} else {
			k1++;
			f1[-a[i]]++;
		}
	}
	int s = 0;
	for (int i = 1; i <= n; i++) {
		int sum = f[i];
		sum += (k1 - f1[i]);
		if (sum == m) {
			can[i] = true;
			s++;
		}
	}
	for (int i = 0; i < n; i++) {
		bool t = false;
		bool t1 = false;
		if (a[i] > 0) {
			if (can[a[i]]) {
				if (s != 1) {
					t1 = true;
				}
				t = true;
			} else {
				t1 = true;
			}
		} else {
			if (s - can[-a[i]] >= 1) {
				t = true;
			}
			if (can[-a[i]]) {
				t1 = true;
			}
		}
		if (t && !t1) {
			cout << "Truth" << endl;
		} else {
			if (!t && t1) {
				cout << "Lie" << endl;
			} else {
				cout << "Not defined" << endl;
			}
		}
	}
	return 0;
}
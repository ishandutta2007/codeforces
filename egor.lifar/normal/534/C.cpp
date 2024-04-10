#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;



int n;
int d[200001];
int b[200001];
long long a;
long long s;


int main() {
	cin >> n >> a;	
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		s += d[i];
	}
	for (int i = 0; i < n; i++) {
		int l = 1;
		int r = d[i];
		while (l != r) {
			int m = (l + r) / 2;
			if (1LL * m + s - 1LL * d[i] < a) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		r = d[i];
		int l1 = 1;
		while (l1 != r) {
			int m = (l1 + r + 1) / 2;
			if (1LL * m + n - 1LL > a) {
				r = m - 1;
			} else {
				l1 = m;
			}
		}
		b[i] = l - 1 + d[i] - r;
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	cout << endl;
	return 0;
}
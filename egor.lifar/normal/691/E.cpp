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


#define Mod 1000000007


struct matrix
{
	int size;
	vector<vector<int> > elems;
	void init(int _size) {
		size = _size;
		elems.resize(size);
		for (int i = 0; i < size; i++) {
			elems[i].resize(size);
		}
	}
};


matrix operator *(matrix a, matrix b) {
	int n = a.size;
	matrix c;
	c.init(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < n; t++) {
				c.elems[i][j] += (1LL * a.elems[i][t] * b.elems[t][j]) % Mod;
				c.elems[i][j] %= Mod;
			}
		}
	}
	return c;
}


matrix f;
int n;
long long k;
vector<long long> a;


matrix powMatrix(matrix a, long long x) {
	if (x == 1LL) {
		return a;
	} else {
		if (x % 2LL == 0LL) {
			matrix b = powMatrix(a, x / 2LL);
			return b * b; 
		} else {
			matrix b = powMatrix(a, x - 1LL);
			return b * f;
		}
	}
}

int main() {
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 1LL) {
		cout << n << endl;
		return 0;
	}
	f.init(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long c = a[i] ^ a[j];
			int cnt = 0;
			while (c > 0) {
				cnt += (c % 2LL == 1LL);
				c /= 2LL;
			}
			if (cnt % 3 == 0) {
				f.elems[i][j] = 1;
			}
		}
	}
	matrix ans = powMatrix(f, k - 1);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += ans.elems[i][j];
			sum %= Mod;
		}
	} 
	cout << sum << endl;
	return 0;
}
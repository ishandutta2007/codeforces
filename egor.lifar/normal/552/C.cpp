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


using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	if (m == 2) {
		cout << "YES" << endl;
		return 0;
	}
	vector<int> v;
	while (m > 0) {
		v.push_back(m % n);
		m /= n;
	}
	bool b = true;
	for (int i = 0; i < (int)v.size(); i++) {
		if (v[i] != 1 && v[i] != 0 && v[i] != n - 1 && v[i] != n) {
			b = false;
			break;
		} else {
			if (v[i] == n - 1 || v[i] == n) {
				v[i + 1]++;
			}
		}
	}
	if (b) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
    return 0;
}
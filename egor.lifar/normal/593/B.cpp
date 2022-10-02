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


using namespace std;


int n;
int x1, x2;
vector<pair<double, int> > v, v1;


int main() {
	cin >> n;
	cin >> x1 >> x2;
	for (int i = 0; i < n; i++) {
		int k, b;
		cin >> k >> b;
		v.push_back(make_pair(1.0 * k * (x1 + 1e-9) + b, i));
		v1.push_back(make_pair(1.0 * k * (x2 - 1e-9) + b, i));
	}
	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	for (int i = 0; i < n; i++) {
		if (v[i].second != v1[i].second) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	a.push_back(1000);
	int cur = -350 + a[0];
	size_t i = 0;
	int solved = 0;
	int penalty = 0;
	while (i < a.size() && cur <= 360) {
		++solved;
		penalty += max(0, cur);
		cur += a[++i];
	}

	cout << solved << ' ' << penalty << '\n';

	return 0;
}
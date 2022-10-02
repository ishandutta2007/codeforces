#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;



int n, T;
int d[101][1001];
vector<int> v[101];



int main() {
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		int t, s;
		cin >> t >> s;
		v[T - t].push_back(s);
		d[0][1] = max(d[0][1], s);
	}
	for (int g = T; g > 0; g--) {
		sort(v[g].begin(), v[g].end());
		for (int i = 0; i <= n; i++) {
			d[g - 1][(i + 1) / 2] = max(d[g - 1][(i + 1) / 2], d[g][i]);
			int t = 0;
			int sum = 0;
			for (int j = (int)v[g].size() - 1; j >= 0; j--) {
				t++;
				sum += v[g][j];
				d[g - 1][(i + t + 1) / 2] = max(d[g - 1][(i + t + 1) / 2], d[g][i] + sum);
			}
		}
	}
	cout << d[0][1] << endl;
    return 0;
}
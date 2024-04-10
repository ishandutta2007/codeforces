#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;


int n;
pair<int, int> k[100];
int d[100][201];
int s = 0;

 
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k[i].first >> k[i].second;
	}
	sort(k, k + n);
	for (int i = 0; i < n; i++) {
		s-= k[i].second;
		d[i][0] = s;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 200; j++) {
			if (i == 0) {
				if (j >= k[i].first) {
					d[i][j] = k[i].first;
				} else {
					d[i][j] = -1000000000;
				}
			} else {
				if (j >= k[i].first) { 
					d[i][j] = max(d[i - 1][j] - k[i].second, d[i - 1][j - k[i].first] + k[i].first);
				} else {
					d[i][j] = d[i - 1][j] - k[i].second;
				}
			}
		}
	}
	int ans = 1000000000;
	for (int i = 1; i <= 200; i++) {
		if (i - d[n - 1][i] <= i) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
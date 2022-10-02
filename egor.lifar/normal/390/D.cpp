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


vector<pair<int, int> > v;


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	int sum = 0;
	for (int i = 2; i <= n + m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < i && sum < k && i - j <= m) {
				int g = i - j;
				sum++;
				ans += j + g - 1;
				v.push_back(make_pair(j, g));
			}
		}	
	}	
	sort(v.begin(), v.end());
	cout << ans << endl;
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		int a = v[i].first;
		int b = v[i].second;
		for (int i = 1; i <= b; i++) {
			printf("(1, %d) ", i); 
		}
		for (int i = 2; i <= a; i++) {
			printf("(%d, %d) ", i, b); 
		}
		cout << endl;
	}
	return 0;
}
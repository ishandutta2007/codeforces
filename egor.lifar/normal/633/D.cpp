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
int a[1001];
unordered_map<int, int> m;


int main() {
	cin >> n;	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int k = 0; k < n; k++) {
		m[a[k]]++;
	}
	int ans = min(2, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (a[i] == a[j] && a[i] == 0) {
				ans = max(ans, m[0]);
				continue;
			}
			vector<int> v;
			v.push_back(a[i]);
			v.push_back(a[j]);
			m[a[i]]--;
			m[a[j]]--;
			int sum = a[i] + a[j];
			int sum1 = a[j];
			int l = 2;
			while (sum <= 1000000000 && sum >= -1000000000) {
				if (m.find(sum) == m.end()) {
					break;
				}
				if (m[sum] == 0) {
					break;
				}
				l++;
				m[sum]--;
				v.push_back(sum);
				int sum2 = sum;
				sum = sum1 + sum;
				sum1 = sum2;
			}
			ans = max(ans, l);
			for (int k = 0; k < (int)v.size(); k++) {
				m[v[k]]++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
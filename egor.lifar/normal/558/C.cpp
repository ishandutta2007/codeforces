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


int n;
int a[100000];
vector<int> v[100000];
int t[100000];



int main() {
	cin >> n;
	int kk = 1000;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		while (a[i]) {
			v[i].push_back(a[i] % 2);
			a[i] /= 2;
		}
		reverse(v[i].begin(), v[i].end());
		kk = min(kk, (int)v[i].size());
	}
	int l = 0;
	while (l < kk) {
		bool b = true;
		for (int i = 1; i < n; i++) {
			if (v[i][l] != v[0][l]) {
				b = false;
				break;
			}
		}
		if (!b) {
			break;
		}
		l++;
	}
	for (int i = 0; i < n; i++) {
		int t1 = 0;
		for (int j = l; j < (int)v[i].size(); j++) {
			if (v[i][j] != 0) {
				break;
			}
			t1++;
		}
		t[i] = t1;
	}
	//cout << l + 1 << endl;
	int ans = 1000 * 1000 * 1000;
	for (int j = max(0, l - 1); j < 20; j++) {
		int ans1 = 0;
		for (int i = 0; i < n; i++) {
			ans1 += (int)v[i].size() - (t[i] + l - 1) - 1;
	//		cout << (int)v[i].size() - (t[i] + l - 1) - 1 << endl;
			ans1 += abs(t[i] + l - 1 - j);
		}
		ans = min(ans, ans1);
	}
	cout << ans << endl;
    return 0;
}
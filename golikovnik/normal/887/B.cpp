#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(6));
	unordered_set<string> nums;
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < 6; ++j) {
			cin >> a[i][j];
			nums.insert(to_string(a[i][j]));
		}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if (j == i) continue;
			for(int ik = 0; ik < 6; ++ik) {
				if (a[i][ik] == 0) continue;
				for (int jk = 0; jk < 6; ++jk) {
					nums.insert(to_string(a[i][ik]) + to_string(a[j][jk]));
				}
			}
		}
	}
	for (int val = 1; val <= 99; ++val) {
		if (nums.find(to_string(val)) == nums.end()) {
			cout << val - 1;
			return 0;
		}
	}	
	cout << 99;
	return 0;
}
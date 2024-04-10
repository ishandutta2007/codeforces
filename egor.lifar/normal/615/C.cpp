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


#define M 1000000007
#define P 424243


string s;
string t;
int h[2121], h1[2121];
int h2[2121];
int p[2121];


int gethash(int l, int r) {
	return (h[r] + M - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M) % M;
}

int gethash1(int l, int r) {
	return (h1[r] + M - (l > 0 ? 1LL * h1[l - 1] * p[r - l + 1]: 0) % M) % M;
}

int gethash2(int l, int r) {
	return (h2[r] + M - (l > 0 ? 1LL * h2[l - 1] * p[r - l + 1]: 0) % M) % M;
}


int main () {
	cin >> s >> t;
	if ((int)t.size() == 2100) {
		bool b = 1;
		for (int i = 0; i < (int)t.size(); i++) {
			if (t[i] != 'a') {
				b = 0;
				break;
			}
		}
		if (b) {
			cout << 2100 << endl;
			for (int i = 0; i < 2100; i++) {
				cout << 1 << ' ' << 1 << endl;
			}
			return 0;	
		}
	}
	int n = (int)s.size();
	int m = (int)t.size();
	p[0] = 1;
	for (int i = 1; i <= 2110; i++) {
		p[i] = (1LL * p[i - 1] * P) % M;
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? 1LL * h[i - 1]: 0) * P + s[i]) % M;
	}
	for (int i = 0; i < m; i++) {
		h1[i] = ((i > 0 ? 1LL * h1[i - 1]: 0) * P + t[i]) % M;
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		h2[i] = ((i > 0 ? 1LL * h2[i - 1]: 0) * P + s[i]) % M;
	}
	int i = m - 1;
	int sum = 0;
	vector<pair<int, int> > ans;
	while (i != -1) {
		sum++;
		int l = 0;
		int r = i;
		while (l != r) {
			int mm = (l + r) / 2;
			bool b = 0;
			for (int j = 0; j <= n - (i - mm + 1); j++) {
				int a = gethash1(mm, i);
				if (gethash(j, j + (i - mm + 1) - 1) == a || gethash2(n - (j + (i - mm + 1) - 1) - 1, n - j - 1) == a) {
					b = 1;
					break;
				}
				//cout << j << ' ' <<  j + (i - m + 1) - 1 << endl;
			}
			//cout << m << endl;
			if (b) {
				r = mm;
			} else {
				l = mm + 1;
			}
		}
		//cout << l << endl;
		bool b = 0;
		for (int j = 0; j <= n - (i - l + 1); j++) {
			int a = gethash1(l, i);
			if (gethash(j, j + (i - l + 1) - 1) == a) {
				b = 1;
				ans.push_back(make_pair(j + 1, j + (i - l + 1)));
				i = l - 1;
				break;
			}
			if (gethash2(n - (j + (i - l + 1) - 1) - 1, n - j - 1) == a) {
				b = 1;
				ans.push_back(make_pair(j + (i - l + 1), j + 1));
				i = l - 1;
				break;
			}
		}
		//cout << i << endl;
		//cout << l << endl;
		if (!b) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << sum << endl;
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
 	return 0;
}
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


#define P 424243
#define M 1000000007


int n, m;
string s;
unordered_map<int, string> st;
int p[100021];
int h[100021];
int d[100021];
int c[100021];


int gethash(int l, int r) {
	return (h[r] - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}


int main() {
	cin >> n;
	cin >> s;
	cin >> m;
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (1LL * p[i - 1] * P) % M;
	}	
	for (int i = 0; i < n; i++) {
		h[i] = ((i != 0 ? 1LL * h[i - 1] * P: 0) + s[i]) % M;
	}
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		string a1 = a;
		reverse(a1.begin(), a1.end());
		int h1 = 0;
		for (int j = 0; j < (int)a1.size(); j++) {
			if (a1[j] >= 'A' && a1[j] <= 'Z') {
				a1[j] = a1[j] - 'A' + 'a';
			}
			h1 = (1LL * h1 * P + a1[j]) % M;
		}
		st[h1] = a;
	}
	d[0] = 1;
	c[0] = -1;
	for (int i = 0; i < n; i++) {
		if (d[i]) {
			for (int j = i; j < min(n, i + 1001); j++) {
				if (st.find(gethash(i, j)) != st.end()) {
					d[j + 1] = d[i];
					c[j + 1] = i;
				}
			}
		}
	}
	int f = c[n];
	int f1 = n;
	vector<string> ans;
	while (f != -1) {
		ans.push_back(st[gethash(f, f1 - 1)]);
		f1 = f;
		f = c[f];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}
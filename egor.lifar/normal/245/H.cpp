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


using namespace std;


#define M 1000000007
#define P 424243


string s;
int q;
int n;
int p[5001];
int h[5000];
int h1[5001];


int gethash(int l, int r) {
	return (h[r] - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}



int gethash1(int l, int r) {
	return (h1[r] - (l > 0 ? 1LL * h1[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}


bool good(int l, int r) {
	return gethash(l, r) == gethash1(n - r - 1, n - l - 1);
}


int f[5001][5001];
int ans[5001][5001];


int main() {
	cin >> s >> q;
	n = (int)s.size();
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (1LL * p[i - 1] * P) % M;
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? 1LL * h[i - 1] * P: 0) % M + s[i]) % M;
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		h1[i] = ((i > 0 ? 1LL * h1[i - 1] * P: 0) % M + s[i]) % M;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			f[j][i] += good(j, i);
			if (j != i) {
				f[j][i] += f[j + 1][i];
			}
		} 
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			int j = i + k - 1;
			if (i != j) {
				ans[i][j] += ans[i][j - 1];
			}
			ans[i][j] += f[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		printf("%d\n", ans[l][r]);
	}
    return 0;
}
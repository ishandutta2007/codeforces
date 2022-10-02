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


int n, k;
string s;
string a;
int d[2001][2001];
int h[100000];
int h1;
int p[3001];



int gethash(int l, int r ) {
	return (h[r] - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}


int g[100000];


int main() {
	cin >> s >> a;
	n = (int)s.size();
	k = (int)a.size();
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (1LL * p[i - 1] * P) % M;
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? (1LL * h[i - 1] * P) % M: 0) + s[i]) % M;
	}
	for (int i = 0; i < k; i++) {
		h1 = ((1LL * h1 * P) % M + a[i]) % M;
	}
	for (int i = 0; i < n; i++) {
		g[i] = i;
		int l = 0;
		while (g[i] < n) {
			if (s[g[i]] == a[l]) {
				l++;
			}
			if (l == k) {
				break;
			}
			g[i]++;
		}
	// /	cout << g[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
		//	cout << d[i][j] << ' ';
			d[i + 1][j] = max(d[i + 1][j], d[i][j]);
			if (g[i] < n) {
				d[g[i] + 1][j + (g[i] - i + 1 - k)] = max(d[g[i] + 1][j + (g[i] - i + 1 - k)], d[i][j] + 1);
			}
			d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j]);
		}
	//	cout << endl;
	}
	for (int i = 0; i <= n; i++) {
		cout << d[n][i] << ' ';
	}
	cout << endl;
    return 0;
}
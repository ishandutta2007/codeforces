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


using namespace std;


#define M 1000000009
#define P 10007
#define M1 1000000007
#define P1 179


int n, m;
string s[300000], s1[300000];
set<long long> setik;
set<long long> setik1;
long long p[700001];
long long p1[700001];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		long long h = 0;
		long long h1 = 0;
		for (int j = 0; j < (int)s[i].size(); j++) {
			h = ((h * P) % M + (long long)s[i][j]) % M;
			h1 = ((h1 * P1) % M1 + (long long)s[i][j]) % M1;
		}
		setik.insert(h);
		setik1.insert(h1);
	//cout << h << endl;
	}
	p[0] = 1;
	p1[0] = 1;
	for (int i = 1; i <= 600000; i++) {
		p[i] = (p[i - 1] * P) % M;
p1[i] = (p1[i - 1] * P1) % M1;
	}
	for (int i = 0; i < m; i++) {
		cin >> s1[i];
		vector<long long> h, h5;
		int l = (int)s1[i].size();
		h.resize(l);
		h5.resize(l);
		for (int j = 0; j < l; j++) {
			h[j] = (((j > 0 ? h[j - 1]: 0) * P) % M + s1[i][j]) % M;
			h5[j] = (((j > 0 ? h5[j - 1]: 0) * P1) % M1 + s1[i][j]) % M1;
		}
		bool b = true;
		for (int j = 0; j < l && b; j++) {
			for (char c = 'a'; c <= 'c' && b; c++) {
				if (c != s1[i][j]) {
					long long h1 = 0;
					if (j > 0) {
						long long h2 = h[j - 1];
						h1 = h2;
					}
					h1 *= P;
					h1 %= M;
					h1 += (long long)c;
					h1 %= M;
				//	cout << h1 << endl;
					if (l != j + 1) {
					//	cout << (((h[l - 1] -  h[j] * p[l - 1 - j]) % M + 3LL * M) % M) << endl;
						h1 = (((((h[l - 1] -  h[j] * p[l - 1 - j]) % M + 3LL * M) % M)) % M + (h1 * p[l - j - 1]) % M) % M;
					}
					long long h3 = 0;
					if (j > 0) {
						long long h4 = h5[j - 1];
						h3 = h4;
					}
					h3 *= P1;
					h3 %= M1;
					h3 += (long long)c;
					h3 %= M1;
				//	cout << h3 << endl;
					if (l != j + 1) {
					//	cout << (((h[l - 1] -  h[j] * p[l - 1 - j]) % M + 3LL * M) % M) << endl;
						h3 = (((((h5[l - 1] -  h5[j] * p1[l - 1 - j]) % M1 + 3LL * M1) % M1)) % M1 + (h3 * p1[l - j - 1]) % M1) % M1;
					}
				//	cout << h1 << endl;
					if (setik.find(h1) != setik.end() && setik1.find(h3) != setik1.end()) {
						cout << "YES" << endl;
						b = false;
						break;
					}
				}
			}
		}
		if (b) {
			cout << "NO" << endl;
		}
	}
    return 0;
}
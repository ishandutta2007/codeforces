#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


#define M 1000000007
#define P 424243
#define M1 1000000009
#define P1 10007


int n;
string s;
string a;
int k;
int d[1500];
int h[1500];
int p[1501];
int h1[1500];
int p1[1501];



int main() {
	cin >> s >> a >> k;
	n = (int)s.size();
	for (int i = 0; i < n; i++) {
		d[i] = (i > 0 ? d[i - 1]: 0) + a[s[i] - 'a'] - '0';
	}
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (1LL * p[i - 1] * P) % M;
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? 1LL * h[i - 1] * P: 0LL) + s[i]) % M;
	}
	p1[0] = 1;
	for (int i = 1; i <= n; i++) {
		p1[i] = (1LL * p1[i - 1] * P1) % M1;
	}
	for (int i = 0; i < n; i++) {
		h1[i] = ((i > 0 ? 1LL * h1[i - 1] * P1: 0LL) + s[i]) % M1;
	}
	set<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (d[j] - (i > 0 ? d[i - 1]: 0) >= j - i + 1 - k) {
				v.insert(make_pair((h[j] + M - (i > 0 ? 1LL * h[i - 1] * p[j - i + 1]: 0) % M) % M, (h1[j] + M1 - (i > 0 ? 1LL * h1[i - 1] * p1[j - i + 1]: 0) % M1) % M1));
			}
		}
	}
	cout << (int)v.size() << endl;
	return 0;	
}
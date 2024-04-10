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


int h[100001];
int h1[100001];
int p[1000001];
string a, b;


int gethash(int l, int r) {
	return (h[r] + M - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M) % M;
}



int gethash1(int l, int r) {
	return (h1[r] + M - (l > 0 ? 1LL * h1[l - 1] * p[r - l + 1]: 0) % M) % M;
}



int main() {
	cin >> a >> b;
	int n = (int)a.size();
	int m = (int)b.size();
	p[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		p[i] = 1LL * p[i - 1] * P % M; 
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? 1LL * h[i - 1] * P: 0) % M + a[i]) % M;
	}
	for (int i = 0; i < m; i++) {
		h1[i] = ((i > 0 ? 1LL * h1[i - 1] * P: 0) % M + b[i]) % M;
	}
	vector<int> s;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			bool bb = true;
			for (int j = 0; j < n; j+= i) {
				if (gethash(0, i - 1) != gethash(j, j + i - 1)) {
					bb = false;
					break;
				}
			}
			if (bb) {
				s.push_back(gethash(0, i - 1));
			}
		}
	}
	vector<int> s1;
	for (int i = 1; i <= m; i++) {
		if (m % i == 0) {
			bool bb = true;
			for (int j = 0; j < m; j+= i) {
				if (gethash1(0, i - 1) != gethash1(j, j + i - 1)) {
					bb = false;
					break;
				}
			}
			if (bb) {
				s1.push_back(gethash1(0, i - 1));
			}
		}
	}
	sort(s.begin(), s.end());
	sort(s1.begin(), s1.end());
	//cout << "opa" << endl;
	vector<int> s2;
	s2.resize(200000);
	vector<int>::iterator it = set_intersection(s1.begin(), s1.end(), s.begin(), s.end(), s2.begin());
	s2.resize(it - s2.begin());
	cout << (int)s2.size() << endl;
 	return 0;
}
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
#include <unordered_set>
#include <set>
 

using namespace std;


#define M 1000000007


int n;
int p[2001][2001];
int a[2001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			t++;
		}
	}
	int t1 = t;
	for (int i = 0; i < n; i++) {
		if (a[i] != -1) {
			if (a[a[i] - 1] == -1) {
				t1--;
			}
		}
	}
	p[0][0] = 1;
	int n1 = 1;
	int n2 = 1;
	for (int i = 1; i <= n; i++) {
		n1 = (1LL * n1 * i) % M;
		p[i][0] = n1;
		p[i][1] = (n1 - n2 + M) % M;
		for (int j = 2; j <= i; j++) {
			p[i][j] = ((1LL * (i - 1) * p[i - 1][j - 1]) % M + (1LL * (j - 1) * (i >= 2 ? p[i - 2][j - 2]: 0)) % M) % M;
		}
		n2 = (1LL * n2 * i) % M;
	}
	cout << p[t][t1] << endl;
 	return 0;
}
/////
//
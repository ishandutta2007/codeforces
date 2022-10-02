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


string s;
int h[2000];
int h1[2000];
int p[2001];
int d[2001];


int main(){
	cin >> s;
	int n = (int)s.size();
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (1LL * P * p[i - 1]) % M;
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? 1LL * h[i - 1]: 0) * P + s[i]) % M;
	}
	for (int i = n - 1; i >= 0; i--) {
		h1[n - i - 1] = ((n - i - 2 >= 0 ? 1LL * h1[n - i - 2]: 0) * P + s[i]) % M;
	}
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			d[i] = d[i - 1];
		}
		for (int j = i; j >= 0; j--) {
			int t = (j + i) / 2;
			int g = i - (t - j);
			if ((h[t] + M - (j > 0 ? 1LL * h[j - 1] * p[t - j + 1]: 0) % M) % M == (h1[n - g - 1] + M - (n - i - 2 >= 0 ? 1LL * h1[n - i - 2] * p[t - j + 1]: 0) % M) % M) {
				d[i]++;
			}
		}
	//	cout << d[i] << endl;
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int k = 0;
		for (int j = i; j < n; j++) {
			int t = (j + i) / 2;
			int g = j - (t - i);
			if ((h[t] + M - (j > 0 ? 1LL * h[i - 1] * p[t - i + 1]: 0) % M) % M == (h1[n - g - 1] + M - (n - j - 2 >= 0 ? 1LL * h1[n - j - 2] * p[t - i + 1]: 0) % M) % M) {
				k++;
			}
		}
		ans += 1LL * d[i - 1] * k;
	}
	cout << ans << endl;
 	return 0;
}
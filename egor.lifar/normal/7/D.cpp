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
#include <unordered_map>


using namespace std;


#define M 1000000007
#define P 424243


int n;
int p[5000005];
int h[5000005];	
int h1[5000005];
int d[5000005];
int m[5000005];
char s[5000005];

int gethash(int l, int r) {
	return (h[r] - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}


int gethash1(int l, int r) {
	return (h1[r] - (l > 0 ? 1LL * h1[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}


int main() {
	scanf("%s", s);
	n = strlen(s);
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (1LL * p[i - 1] * P) % M; 
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? 1LL * h[i - 1] * P: 0) % M + s[i]) % M;
	}
	//cout << gethash(n - 3, n - 1) << endl;
	//cout << s << endl;
	for (int i = 0; i < n; i++) {
		h1[i] = ((i > 0 ? 1LL * h1[i - 1] * P: 0) % M + s[n - i - 1]) % M;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans++;
			m[i] = 1;
		} else {
			if (h[i] == gethash1(n - i - 1, n - 1)) {
				ans += 1 + m[(i - 1) / 2];
				m[i] = 1 + m[(i - 1) / 2]; 
			}
		}
//		cout << get(0, i) << endl;
	}
	cout << ans << endl;
    return 0;
}
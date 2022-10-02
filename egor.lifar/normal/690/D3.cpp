#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <queue>


using namespace std;


#define Mod 1000003
int c, w, h;
int dp[102];
int st[102];


int main() {
	cin >> c >> w >> h;
	st[0] = 1;
	for (int i = 1; i <= w; i++) {
		st[i] = (1LL * st[i - 1] * h) % Mod;
	}
	int sum = 0;
	for (int i = 0; i < c; i++) {
		if (i <= w + 1) {
			dp[i] = (i != 0 ? dp[i - 1]: 1);
			for (int j = i - 1; j >= max(-1, i - w); j--) {
				//cout << (i - j) << endl;
				dp[i] += (1LL * st[i - j] * (j > 0 ? dp[j - 1]: 1)) % Mod;
				if (dp[i] >= Mod) {
					dp[i] -= Mod;
				}
			}
			//cout << dp[i] << endl;
		} else {
			//cout << "opa" << endl;
			if (i == w + 2) {
				for (int j = i - w - 2; j < i - 1; j++) {
					dp[j - (i - w - 2)] = dp[j - (i - w - 2) + 1];
				}
				for (int j = 0; j < w; j++) {
					sum += (1LL * st[w - j] * dp[j]) % Mod;
					if (sum > Mod) sum -= Mod;
				}
			} else {
				sum -= (1LL * dp[0] * st[w]) % Mod;
				if (sum < 0) {
					sum += Mod;
				}
				sum = (1LL * sum * st[1]) % Mod;
				for (int j = i - w - 2; j < i - 1; j++) {
					dp[j - (i - w - 2)] = dp[j - (i - w - 2) + 1];
				}
				sum += (1LL * st[1] * dp[w - 1]) % Mod;
				if (sum > Mod) sum -= Mod;
			}
			dp[w + 1] = dp[w] + sum;
			dp[w + 1] %= Mod;
		}
	}
	cout << dp[min(c - 1, w + 1)] << endl;
	return 0;
}
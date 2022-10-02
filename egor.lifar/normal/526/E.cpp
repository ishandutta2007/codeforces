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


int n, q;
int a[1000000];
long long d[1000000];
int dp[1000001];
int dp1[1000001];


int main(){
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		d[i] += 1LL * a[i];
		d[i] += (i > 0 ? d[i - 1]: 0);
	}
	for (int k = 0; k < q; k++) {
		long long b;
		cin >> b;
		int r = n - 1;
		int ans = 1000000;
		for (int i = n - 1; i >= 0; i--) {
			while (true) {
				if (d[r] - (i > 0 ? d[i - 1]: 0) > b) {
					r--;
				} else {
					break;
				}
			}
			//cout << r << endl;
			if (r == n - 1) {
				dp[i] = 0;
				dp1[i] = i;
				continue;
			}
			dp[i] = dp[r + 1] + 1;
			dp1[i] = dp1[r + 1];
			//cout << r + 1 << endl;
		}
		for (int i = 0; i < n; i++) {
			//cout << dp[i] << endl;
			long long s = 0;
			int t = 0;
			if (i > 0) {
				s += d[i - 1];
				t = 1;
			}
			if (dp1[i] != n) {
				s += d[n - 1] - (dp1[i] > 0 ? d[dp1[i] - 1]: 0);
				t = 1; 
			}
			if (s <= b) {
				ans = min(ans, t + dp[i]);
			}
			if (i > 0 && dp1[i] != n) {
				if (d[n - 1] - (dp1[i] > 0 ? d[dp1[i] - 1]: 0) <= b && d[i - 1] <= b) {
					ans = min(ans, 2 + dp[i]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
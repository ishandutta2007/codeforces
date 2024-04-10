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
#include <vector>

using namespace std;


#define M 1000000007


int n, k;
int d[201][2001];
int l[201][2001];
int r[201][2001];
int a[2001];
int dp[201][2001];


inline void add(int& a, int b) {
	if ((a += b) >= M) {
		a -= M;
	}
}



inline int g(int i, int j, int z) {
    if (j < 0 || j > i || j > n - i) {
        return 0;
    }
    if (l[i][j] <= z && z <= r[i][j]) {
        return d[j][z - l[i][j]];
    }
    return 0;
}



int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	d[0][0] = 1; 
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i && j <= n - i; ++j) {
			l[i][j] = -a[i] * j;
			r[i][j] = k - a[i] * j;
		}	
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i && j <= n - i; ++j) {
			for (int z = l[i][j]; z <= r[i][j]; ++z) {
				dp[j][z - l[i][j]] = 0;
				add(dp[j][z - l[i][j]], g(i - 1, j - 1, z + a[i]));
				add(dp[j][z - l[i][j]], (1LL * g(i - 1, j + 1, z - a[i]) * (j + 1)) % M);
				add(dp[j][z - l[i][j]], (1LL * g(i - 1, j, z) * (j + 1)) % M);
			}
		}
		for (int j = 0; j <= i && j <= n - i; ++j) {
            for (int z = l[i][j]; z <= r[i][j]; ++z) {
                d[j][z - l[i][j]] = dp[j][z - l[i][j]];
            }
        }
	}
	int ans = 0;
    for (int i = l[n][0]; i <= r[n][0]; ++i) {
        if (i <= k) {
        	//cout << d[0][i - l[n][0]] << endl;
            add(ans, d[0][i - l[n][0]]);
        }
    }
    cout << ans << endl;
	return 0;
}
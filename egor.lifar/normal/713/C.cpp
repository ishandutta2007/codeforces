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
#include <bitset>
#include <unordered_map>


using namespace std;


int n;
int a[3001];
int t[3001][3001];
long long dp[3001][3001];


int main() {    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[i][j] = a[j] + i - j;
        }
        sort(t[i], t[i] + n);
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = abs(a[0] - t[0][i]);
        if (i != 0) {
            dp[0][i] = min(dp[0][i], dp[0][i - 1]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int uk = (lower_bound(t[i - 1], t[i - 1] + n, t[i][j]) - t[i - 1]) - 1;
            dp[i][j] = (long long)1e18;
            if (uk >= 0) {
                dp[i][j] = dp[i - 1][uk] + abs(t[i][j] - a[i]);
            }
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}
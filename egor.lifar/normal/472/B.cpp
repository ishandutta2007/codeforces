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
#include <assert.h>


using namespace std;



int n, k;
int f[100000];
int ans = 0;
int dp[100000];



int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    sort(f, f + n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1000000000;
        for (int j = i; j >= max(i - k + 1, 0); j--) {
            dp[i] = min(dp[i], f[i] * 2 - 2 + (j > 0 ? dp[j - 1]: 0));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
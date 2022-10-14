// Codeforces Beta Round #76
// Problem E -- Lastborn
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int K = 111;
const int N = 55555;

int k, a[K], dp[K][N];
long long n;

long long dfs (int k, long long n) {
    if (k == 0 or n == 0) {
        return n;
    }
    if (n < N) {
        if (~dp[k][n] == 0) {
            dp[k][n] = dfs(k - 1, n) - dfs(k - 1, n / a[k - 1]);
        }
        return dp[k][n];
    } 
    return dfs(k - 1, n) - dfs(k - 1, n / a[k - 1]);
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < k; ++ i) {
        cin >> a[i];
    }
    sort(a, a + k);
    memset(dp, 255, sizeof(dp));
    cout << dfs(k, n) << endl;
    return 0;
}
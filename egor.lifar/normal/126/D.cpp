#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <algorithm>


using namespace std;


vector<long long> fib;


void prep() {
    fib.push_back(1);
    fib.push_back(2);
    while (fib.back() <= 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }
}


long long stupid(long long t, int pos) {
    if (t < 0) {
        return 0;
    }
    if (t == 0) {
        return 1;
    }
    if (pos == -1) {
        return 0;
    }
    return stupid(t, pos - 1) + stupid(t - fib[pos], pos - 1);
}


long long dp[100][16];


long long solve(long long t) {
    vector<int> ans;
    vector<long long> cus;
    for (int i = (int)fib.size() - 1; i >= 0; i--) {
        cus.push_back(t);
        if (t >= fib[i]) {
            ans.push_back(1);
            t -= fib[i];
        } else {
            ans.push_back(0);
        }
    }
    reverse(ans.begin(), ans.end());
    reverse(cus.begin(), cus.end());
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= (int)ans.size(); i++) {
        for (int j = 0; j < 16; j++) {
            if (ans[i-1]) {
                if (!(j & 8)) {
                    dp[i][j] += dp[i-1][(j << 1) + 2];
                    dp[i][j] += dp[i-1][(j << 1)];
                }
            } else {
                if (!(j & 8)) {
                    dp[i][j] += dp[i-1][j << 1];
                }
                if (j) {
                    int bits[2] = {0};
                    if (j & 8) {
                        bits[0] += 2;
                        bits[1] += 3;
                    }
                    if (j & 4) {
                        bits[0] += 1;
                        bits[1] += 2;
                    }
                    if (j & 2) {
                        bits[0] += 1;
                        bits[1] += 1;
                    }
                    if (j & 1) {
                        bits[0] += 0;
                        bits[1] += 1;
                    }
                    bits[1]--;
                    int jn = 0;
                    if (bits[1] >= 2 && bits[0] >= 1) {
                        bits[1] -= 2;
                        bits[0] -= 1;
                        jn |= 8;
                    }
                    if (bits[1] >= 1 && bits[0] >= 1) {
                        bits[1] -= 1;
                        bits[0] -= 1;
                        jn |= 4;
                    }
                    if (bits[1] >= 1 && bits[0] >= 0) {
                        bits[1] -= 1;
                        bits[0] -= 0;
                        jn |= 2;
                    }
                    if (bits[1] >= 0 && bits[0] >= 1) {
                        bits[1] -= 0;
                        bits[0] -= 1;
                        jn |= 1;
                    }
                    if (!bits[0] && !bits[1]) {
                        dp[i][j] += dp[i - 1][jn];
                    }
                }
            }
        }
    }
    return dp[ans.size()][0];
}


int main() {
    prep();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long t;
        scanf("%I64d", &t);
        printf("%I64d\n", solve(t));
    }
    return 0;
}
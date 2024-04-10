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


#define INF 1000000007


int n, k, d;
long long dp[101];
long long dp1[101];


int main() {
    cin >> n >> k >> d;
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= d - 1; j++) {
            if (i >= j) {
                dp[i] += dp[i - j];
                dp[i] %= INF;
            } 
        }
    }
    dp1[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j) {
                dp1[i] += dp1[i - j];
                dp1[i] %= INF;
            } 
        }
    }
    cout << (dp1[n] - dp[n] + INF) % INF << endl;
    return 0;
}
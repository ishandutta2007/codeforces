#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>



using namespace std;


int n;
long double d[18][18];
long double dp[262145][19];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dd;
            cin >> dd;
            d[i][j] = dd;
        }
    }
    if (n == 1) {
        cout << 1.0 << endl;
        return 0;
    }
    int maxmask = (1 << n) - 1;
    for (int i = 0; i <= maxmask; i++) {
        int i1 = i;
        int cnt = 0;
        vector<int> pos;
        int mask = i;
        for (int j = 0; j < n; j++) {
            if (i1 % 2 == 1) {
                cnt++;
                pos.push_back(j);
            }
            i1 /= 2;
        }
        if (pos.empty() || pos[0] != 0) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0.0;
            }
            continue;
        }
        if (cnt == 1) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j] = 1.0;
                } else {
                    dp[i][j] = 0.0;
                }
            }
            continue;
        }
        if (i == maxmask) {
            for (int j = 0; j < n; j++) {
                for (int g = j + 1; g < n; g++) {
                    if (j == 0) {
                        dp[i][n] = max(dp[i][n], d[j][g] * dp[mask ^ (1 << g)][j]);
                        continue;
                    }
                    dp[i][n] = max(dp[i][n], d[g][j] * dp[mask ^ (1 << j)][g] + d[j][g] * dp[mask ^ (1 << g)][j]);
                }
            }
            continue;
        }
        for (int jj = 0; jj < (int)pos.size(); jj++) {
            int ind = pos[jj];
            for (int j = 0; j < (int)pos.size(); j++) {
                if (j == jj) {
                    continue;
                }
                if (j == 0) {
                    dp[i][ind] = max(dp[i][ind],  d[pos[j]][ind] * dp[mask ^ (1 << ind)][pos[j]]);
                    continue;
                }
                dp[i][ind] = max(dp[i][ind], d[pos[j]][ind] * dp[mask ^ (1 << ind)][pos[j]] + d[ind][pos[j]] * dp[mask ^ (1 << pos[j])][ind]);
            }
        }
    }
    printf("%.15lf\n", (double)dp[maxmask][n]);
    return 0;       
}
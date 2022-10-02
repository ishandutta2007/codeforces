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


const double eps = 1e-9;
double dp[(1 << 20) + 7];
double p[27];
int n, k;


int countBits(int n) {
    int res = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            res++;
        }
        n /= 2;
    }
    return res;
}


int main() {
    scanf("%d %d", &n, &k);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
        if (p[i] >= eps) {
            cnt++;
        }
    }
    k = min(k, cnt);
    dp[0] = 1;
    for (int i = 1; i < (1 << n); i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) {
                sum += p[j];
            }
        }
        for (int j = 0; j < n; j++)  {
            if ((i & (1 << j)) != 0) {
                dp[i] += dp[i ^ (1 << j)] * p[j] / (sum + p[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        double ans = 1;
        for (int j = 0; j < (1 << n); j++) {
            if (countBits(j) != k) {
                continue;
            }
            if ((j & (1 << i)) == 0) {
                ans -= dp[j];
            }
        }
        printf("%.9lf ", ans);
    }
    printf("\n");
    return 0;
}
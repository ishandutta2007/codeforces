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


using namespace std;


#define INF 1000000000000000000LL


int n, k;
int a[300000];
long long dp[5002][5002];
long long sum[300001];


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int s = n / k;
    int B = n % k;
    int A = k - B;
    for (int i = 0; i <= A; i++) {
      for (int j = 0; j <= B; j++) {
        dp[i][j] = INF;
      }
    }
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
      sum[i] = sum[i - 1];
      sum[i] += 1LL * (a[i] - a[i - 1]); 
    }
    for (int i = 0; i <= A; i++) {
      for (int j = 0; j <= B; j++) {
        int x = (i + j) * s + j;
        if (i < A) {
          long long h = dp[i][j] + sum[x + s - 1] - sum[x];
          dp[i + 1][j] = min(dp[i + 1][j], h);
        }
        if (j < B) {
          long long h = dp[i][j] + sum[x + s] - sum[x];
          dp[i][j + 1] = min(dp[i][j + 1], h);
        }
      }
    } 
    cout << dp[A][B] << endl;
    return 0;
}
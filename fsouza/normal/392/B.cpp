#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 40

typedef long long lint;

using namespace std;

lint cost[3][3];
lint dp[MAXN+1][3][3];

int main(int argc, char ** argv)
{
        for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                        cin >> cost[i][j];

        int wantn;

        cin >> wantn;

        for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                        dp[0][i][j] = 0;

        for (int n = 1; n <= wantn; n++) {
                for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++) {
                                if (i == j) dp[n][i][j] = 0;
                                else {
                                        const int k = 0+1+2-i-j;

                                        dp[n][i][j] = dp[n-1][i][j] + cost[i][k] + dp[n-1][j][i] + cost[k][j] + dp[n-1][i][j];
                                        dp[n][i][j] = min(dp[n][i][j], dp[n-1][i][k] + cost[i][j] + dp[n-1][k][j]);
                                }
                        }
                for (int k = 0; k < 3; k++)
                        for (int i = 0; i < 3; i++)
                                for (int j = 0; j < 3; j++)
                                        dp[n][i][j] = min(dp[n][i][j], dp[n][i][k] + dp[n][k][j]);
        }

        cout << dp[wantn][0][2] << endl;

        return 0;
}
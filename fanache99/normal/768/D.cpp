//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const double EPS = 1e-7;
const int MAXS = 10000;
const int MAXK = 1000;

double dp[1 + MAXS][1 + MAXK + 1];

int main() {
    int k, q;
    cin >> k >> q;
    dp[1][1] = 1.0;
    for (int i = 1; i < MAXS; i++)
        for (int j = 1; j <= min(i, k); j++) {
            dp[i + 1][j] += dp[i][j] * j / k;
            dp[i + 1][j + 1] += dp[i][j] * (k - j) / k;
        }
    for (int i = 1; i <= q; i++) {
        int p;
        cin >> p;
        int left = k, right = MAXS, answer = MAXS;
        double chance = (1.0 * p - EPS) / 2000.0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (dp[middle][k] > chance) {
                answer = middle;
                right = middle - 1;
            }
            else
                left = middle + 1;
        }
        cout << answer << "\n";
    }
    return 0;
}
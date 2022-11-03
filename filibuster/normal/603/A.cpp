#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 500 + 13;

/*
*/

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> dp0(n + 1, vector<int>(3, 0));
    vector<vector<int>> dp1(n + 1, vector<int>(3, 0));
    for(int i = 0; i < n; i++) {
        dp0[i + 1] = dp0[i];
        dp1[i + 1] = dp1[i];
        if(s[i] == '0') {
            dp1[i + 1][0] = max(dp1[i + 1][0], dp0[i][0] + 1);
            dp0[i + 1][1] = max(dp0[i + 1][1], dp1[i][0] + 1);
            dp0[i + 1][1] = max(dp0[i + 1][1], dp1[i][1] + 1);
            dp1[i + 1][2] = max(dp1[i + 1][2], dp0[i][1] + 1);
            dp1[i + 1][2] = max(dp1[i + 1][2], dp0[i][2] + 1);
        } else {
            dp0[i + 1][0] = max(dp0[i + 1][0], dp1[i][0] + 1);
            dp1[i + 1][1] = max(dp1[i + 1][1], dp0[i][0] + 1);
            dp1[i + 1][1] = max(dp1[i + 1][1], dp0[i][1] + 1);
            dp0[i + 1][2] = max(dp0[i + 1][2], dp1[i][1] + 1);
            dp0[i + 1][2] = max(dp0[i + 1][2], dp1[i][2] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < 3; i++) {
        ans = max(ans, dp0[n][i]);
        ans = max(ans, dp1[n][i]);
    }
    cout << ans;
}
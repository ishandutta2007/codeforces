#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k;
int dp[1005][2005];
char s[2005];

int main()
{
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 1005; ++i)
        for (int j = 0; j < 2005; ++j)
            dp[i][j] = 0x3F3F3F3F;

    cin >> n >> k >> (s + 1);
    dp[0][1000] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = -k + 1; j <= k - 1; ++j) {
            if (dp[i][j + 1000] == 0x3F3F3F3F)
                continue;
            int L = -1, R = 1;
            if (s[i + 1] == 'L')
                L = R = -1;
            else if (s[i + 1] == 'D')
                L = R = 0;
            else if (s[i + 1] == 'W')
                L = R = 1;
            for (; L <= R; ++L)
                dp[i + 1][j + 1000 + L] = L;
        }
    }

    int y = n, x = k + 1000;
    if (dp[y][x] == 0x3F3F3F3F)
        x = -k + 1000;
    if (dp[y][x] == 0x3F3F3F3F) {
        cout << "NO\n";
        return 0;
    }

    while (y) {
        if (dp[y][x] == 1)
            s[y] = 'W';
        else if (dp[y][x] == 0)
            s[y] = 'D';
        else if (dp[y][x] == -1)
            s[y] = 'L';
        x -= dp[y][x];
        --y;
    }

    cout << (s + 1) << endl;

    return 0;
}
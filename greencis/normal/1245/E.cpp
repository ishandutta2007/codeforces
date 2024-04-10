#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ld dp[100];
int h[10][10];

int main() {
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> h[i][j];

    dp[0] = 0;
    for (int i = 1; i < 100; ++i) {
        int extra = 0;
        ld cur = 0;
        for (int j = 1; j <= 6; ++j) {
            int nxt = i - j;
            if (nxt < 0) {
                ++extra;
                continue;
            }
            int y = nxt / 10;
            int x = nxt % 10;
            if (y % 2)
                x = 9 - x;
            y -= h[y][x];
            if (y % 2)
                x = 9 - x;
            int alter = y * 10 + x;
            cur += min(dp[nxt], dp[alter]);
        }
        cur += 6;
        cur /= 6 - extra;
        dp[i] = cur;
    }

    cout << setprecision(17) << fixed << dp[99] << endl;
}
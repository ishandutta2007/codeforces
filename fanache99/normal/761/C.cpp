//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 50;
const int INF = 1000000;

char s[1 + MAXN][1 + MAXN];
int dp[1 + MAXN][2][2][2];

int Distance(int y, int n) {
    return min(y - 1, n - y + 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i] + 1;
    for (int i = 0; i <= n; i++)
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++)
                for (int c = 0; c < 2; c++)
                    dp[i][a][b][c] = INF;
    dp[0][0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++)
                for (int c = 0; c < 2; c++)
                    for (int j = 1; j <= m; j++) {
                        int add = Distance(j, m);
                        int a0 = 0, b0 = 0, c0 = 0;
                        if (s[i + 1][j] >= 'a' && s[i + 1][j] <= 'z')
                            a0 = 1;
                        else
                            if (s[i + 1][j] >= '0' && s[i + 1][j] <= '9')
                                b0 = 1;
                            else
                                c0 = 1;
                        dp[i + 1][a | a0][b | b0][c | c0] = min(dp[i + 1][a | a0][b | b0][c | c0], dp[i][a][b][c] + add);
                    }
    cout << dp[n][1][1][1] << "\n";
    return 0;
}
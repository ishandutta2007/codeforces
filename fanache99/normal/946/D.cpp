#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 500;
const int INF = 1000000000;

char s[1 + MAXN];
int dp[1 + MAXN][1 + MAXN], lessons[1 + MAXN], best[1 + MAXN][1 + MAXN];
int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s\n", s + 1);
        for (int j = 1; j <= m; j++)
            if (s[j] == '1') {
                lessons[i]++;
                v[lessons[i]] = j;
            }
        for (int j = 0; j < lessons[i]; j++) {
            int other = lessons[i] - j;
            best[i][j] = INF;
            for (int x = 1; x + other - 1 <= lessons[i]; x++)
                best[i][j] = min(best[i][j], v[x + other - 1] - v[x] + 1);
        }
        best[i][lessons[i]] = 0;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        dp[0][i] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INF;
            for (int p = 0; p <= lessons[i] && p <= j; p++)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - p] + best[i][p]);
        }
    while (dp[n][k] == INF)
        k--;
    printf("%d\n", dp[n][k]);
    return 0;
}
#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

const int SIZE = 1 << 17;
const int MAXN = 80;
const int INF = 1000000;
const int MAXM = 2000;

char buffer[SIZE];
int pointer = SIZE;

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

int dp[1 + MAXN][1 + MAXN][1 + MAXN];
int a[1 + MAXM], b[1 + MAXM], c[1 + MAXM];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int l = 2; l <= k; l++)
                dp[i][j][l] = INF;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for (int l = 2; l <= k; l++)
        for (int i = 1; i <= m; i++)
            if (a[i] < b[i])
                for (int j = b[i]; j <= n; j++)
                    dp[a[i]][j][l] = min(dp[a[i]][j][l], c[i] + min(dp[b[i]][j][l - 1], dp[b[i]][a[i] + 1][l - 1]));
            else
                for (int j = b[i]; j >= 1; j--)
                    dp[a[i]][j][l] = min(dp[a[i]][j][l], c[i] + min(dp[b[i]][j][l - 1], dp[b[i]][a[i] - 1][l - 1]));
    int answer = INF;
    for (int i = 1; i <= n; i++)
        answer = min(answer, min(dp[i][1][k], dp[i][n][k]));
    if (answer == INF)
        answer = -1;
    printf("%d\n", answer);
    return  0;
}
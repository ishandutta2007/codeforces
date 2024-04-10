#include <bits/stdc++.h>

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

const long long INF = 1000000000000000000LL;
const int MAXN = 300000;

int h[1 + MAXN], c[1 + MAXN];
long long dp[1 + MAXN][3];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &h[i], &c[i]);
        for (int i = 1; i <= n; i++)
            for (int a = 0; a < 3; a++) {
                dp[i][a] = INF;
                for (int b = 0; b < 3; b++)
                    if (h[i - 1] + b != h[i] + a)
                        dp[i][a] = min(dp[i][a], dp[i - 1][b] + a * c[i]);
            }
        printf("%I64d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
    }
    return 0;
}
#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

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

const int MAXN = 100000;
const int SIGMA = 26;

char a[1 + MAXN], b[1 + MAXN + 1];
int preffix[1 + MAXN];
int to[1 + MAXN][SIGMA];
int **dp;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s%s", a + 1, b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);
    dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[m + 1];
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;
    }
    int i = 0;
    for (int j = 2; j <= m; j++) {
        while (i && b[i + 1] != b[j])
            i = preffix[i];
        if (b[i + 1] == b[j])
            i++;
        preffix[j] = i;
    }
    for (int j = 0; j <= m; j++)
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (b[j + 1] != ch)
                to[j][ch - 'a'] = to[preffix[j]][ch - 'a'];
            else
                to[j][ch - 'a'] = j + 1;
        }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (dp[i - 1][j] != -1)
                if (a[i] != '?') {
                    int k = to[j][a[i] - 'a'];
                    if (k != m)
                        dp[i][k] = max(dp[i][k], dp[i - 1][j]);
                    else
                        dp[i][k] = max(dp[i][k], dp[i - 1][j] + 1);
                }
                else
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        int k = to[j][ch - 'a'];
                        if (k != m)
                            dp[i][k] = max(dp[i][k], dp[i - 1][j]);
                        else
                            dp[i][k] = max(dp[i][k], dp[i - 1][j] + 1);
                    }
    int answer = 0;
    for (int j = 0; j <= m; j++)
        answer = max(answer, dp[n][j]);
    printf("%d\n", answer);
    return 0;
}
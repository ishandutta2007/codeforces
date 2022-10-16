#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

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

const int MAXN = 15;
const int MAXM = 100;

char s[1 + MAXN][1 + MAXM];
int dp[1 + MAXN][2];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s\n", s[i] + 1);
    for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= m + 2; j++)
            swap(s[i][j], s[n - i + 1][j]);
    while (n) {
        bool found = false;
        for (int i = 1; i <= m + 1; i++)
            if (s[n][i] == '1') {
                found = true;
                break;
            }
        if (found)
            break;
        n--;
    }
    if (!n) {
        printf("0\n");
        return 0;
    }
    dp[1][0] = 0;
    dp[1][1] = m + 1;
    for (int i = 2; i <= n; i++) {
        int j = m + 2;
        while (j > 1 && s[i - 1][j] == '0')
            j--;
        dp[i][0] = min(dp[i - 1][1] + m + 1, dp[i - 1][0] + 2 * (j - 1)) + 1;
        j = 1;
        while (j < m + 2 && s[i - 1][j] == '0')
            j++;
        dp[i][1] = min(dp[i - 1][0] + m + 1, dp[i - 1][1] + 2 * (m + 2 - j)) + 1;
    }
    int j = 1;
    while (j < m + 2 && s[n][j] == '0')
        j++;
    int answer = dp[n][1] + (m + 2 - j);
    j = m + 2;
    while (j > 1 && s[n][j] == '0')
        j--;
    answer = min(answer, dp[n][0] + (j - 1));
    printf("%d\n", answer);
    return 0;
}
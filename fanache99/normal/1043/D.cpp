#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

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

const int MAXN = 100000;
const int MAXM = 10;

int p[1 + MAXM][1 + MAXN];
int dp[1 + MAXM][1 + MAXN];
int where[1 + MAXM][1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read();
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = Read();
            where[i][p[i][j]] = j;
        }
        if (i == 1)
            for (int j = 1; j <= n; j++)
                dp[i][p[i][j]] = n - j + 1;
        else
            for (int j = 1, k; j <= n; j += k) {
                int j0 = where[i - 1][p[i][j]];
                k = 0;
                while (j + k <= n && j0 + k <= n && p[i][j + k] == p[i - 1][j0 + k])
                    k++;
                for (int x = j; x < j + k; x++)
                    dp[i][p[i][x]] = min(dp[i - 1][p[i][x]], j + k - x);
            }
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
        answer += dp[m][i];
    printf("%I64d\n", answer);
    return 0;
}
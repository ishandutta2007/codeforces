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

const int MAXN = 2000;
const int MOD = 998244353;

int dp[1 + MAXN][1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    dp[1][0] = m;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j != 0)
                dp[i][j] = (1LL * (m - 1) * dp[i - 1][j - 1] + dp[i][j]) % MOD;
        }
    printf("%d\n", dp[n][k]);
    return 0;
}
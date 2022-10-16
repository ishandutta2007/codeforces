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

const int MAXN = 5000;

int v[1 + MAXN];
int dp[1 + MAXN][1 + MAXN];

void Precompute(int n) {
    for (int i = 1; i <= n; i++)
        dp[i][i] = v[i];
    for (int l = 2; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            dp[i][j]= dp[i][j - 1] ^ dp[i + 1][j];
        }
    for (int l = 2; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            dp[i][j] = max(max(dp[i][j - 1], dp[i + 1][j]), dp[i][j]);
        }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        v[i] = Read();
    Precompute(n);
    int q = Read();
    for (int i = 1; i <= q; i++) {
        int a = Read(), b = Read();
        printf("%d\n", dp[a][b]);
    }
    return 0;
}
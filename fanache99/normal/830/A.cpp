//#inlude <iostream>
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
#include <cstring>

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

const int MAXN = 1000;
const int MAXK = 2000;
const int INF = 2000000000;

int a[1 + MAXN], b[1 + MAXK];
int dp[1 + MAXN][1 + MAXK];

int Distance(int x, int y, int z) {
    if (x <= z)
        if (y < x)
            return x - y + z - y;
        else
            if (y <= z)
                return z - x;
            else
                return y - x + y - z;
    else
        if (y > x)
            return y - x + y - z;
        else
            if (y >= z)
                return x - z;
            else
                return x - y + z - y;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i++)
        scanf("%d", &b[i]);
    sort(b + 1, b + k + 1);
    for (int i = 1; i <= n; i++)
        dp[i][0] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            dp[i][j] = INF;
        for (int j = i; j <= k; j++)
            dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1], Distance(a[i], b[j], p)));
    }
    printf("%d\n", dp[n][k]);
    return 0;
}
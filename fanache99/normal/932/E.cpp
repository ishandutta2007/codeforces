#include <fstream>
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

long long Read() {
    long long answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

char ReadCh() {
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    return ch;
}

const int MOD = 1000000007;
const int MAXM = 5000;

int dp[1 + MAXM][1 + MAXM];

int RaiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

void Add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int Brute(int n, int m) {
    int answer = 0, combinations = 1;
    for (int k = 1; k <= n; k++) {
        combinations = (1LL * combinations * (n - k + 1)) % MOD;
        combinations = (1LL * combinations * RaiseToPower(k, MOD - 2)) % MOD;
        Add(answer, (1LL * combinations * RaiseToPower(k, m)) % MOD);
    }
    return answer;
}

int Smart(int n, int m) {
    dp[1][1] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j <= i; j++) {
            Add(dp[i + 1][j + 1], dp[i][j]);
            Add(dp[i + 1][j], (1LL * j * dp[i][j]) % MOD);
        }
    int power2 = RaiseToPower(2, n), divide2 = RaiseToPower(2, MOD - 2), multiply = n, factor = 1, answer = 0;
    for (int i = 1; i <= m; i++) {
        factor = (1LL * factor * multiply) % MOD;
        multiply--;
        power2 = (1LL * power2 * divide2) % MOD;
        int current = (1LL * factor * power2) % MOD;
        current = (1LL * current * dp[m][i]) % MOD;
        Add(answer, current);
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    if (n < m)
        printf("%d\n", Brute(n, m));
    else
        printf("%d\n", Smart(n, m));
    return 0;
}
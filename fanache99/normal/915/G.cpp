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

const int MAXN = 2000000;
const int MOD = 1000000007;

int dp[1 + MAXN], sum[1 + MAXN + 1];

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

void Subtract(int &x, int y) {
    x -= y;
    if (x < 0)
        x += MOD;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    int answer = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = RaiseToPower(i, n);
        //for (int j = 2; j <= i; j++)
           // Subtract(dp[i], dp[i / j]);
    }
    for (int i = 1; i <= k; i++) {
        Add(sum[i], sum[i - 1]);
        Subtract(dp[i], sum[i]);
        Add(answer, dp[i] ^ i);
        for (int j = 1; i * j <= k; j++) {
            Add(sum[i * j], dp[i]);
            Subtract(sum[min(k + 1, (i + 1) * j)], dp[i]);
        }
    }
    printf("%d\n", answer);
    return 0;
}
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

const int MOD = 998244353;
const int MAXD = 19;
const int SIGMA = 10;

int active[1 + MAXD + 1][1 << SIGMA][2][2], sum[1 + MAXD + 1][1 << SIGMA][2][2];
int power10[1 + MAXD];
int digit[1 + MAXD];

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

int Count(long long n, int k) {
    for (int i = 1; i <= MAXD; i++) {
        digit[i] = n % 10;
        n /= 10;
    }
    memset(active, 0, sizeof(active));
    memset(sum, 0, sizeof(sum));
    active[MAXD + 1][0][0][0] = 1;
    for (int i = MAXD; i >= 1; i--)
        for (int mask = 0; mask < (1 << SIGMA); mask++)
            for (int nonZero = 0; nonZero < 2; nonZero++)
                for (int smaller = 0; smaller < 2; smaller++)
                    for (int d = 0; d < SIGMA; d++)
                        if (smaller || d <= digit[i]) {
                            int newMask = mask;
                            if (nonZero || d != 0)
                                newMask |= (1 << d);
                            int newNonZero = nonZero | (d != 0);
                            int newSmaller = smaller | (d < digit[i]);
                            int value = (1LL * power10[i - 1] * d) % MOD;
                            Add(active[i][newMask][newNonZero][newSmaller], active[i + 1][mask][nonZero][smaller]);
                            Add(sum[i][newMask][newNonZero][newSmaller], (1LL * value * active[i + 1][mask][nonZero][smaller] + sum[i + 1][mask][nonZero][smaller]) % MOD);
                        }
    int answer = 0;
    for (int mask = 0; mask < (1 << SIGMA); mask++)
        if (__builtin_popcount(mask) <= k)
            Add(answer, sum[1][mask][1][1]);
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    power10[0] = 1;
    for (int i = 1; i <= MAXD; i++)
        power10[i] = (1LL * power10[i - 1] * 10) % MOD;
    long long a, b;
    int k;
    scanf("%I64d%I64d%d", &a, &b, &k);
    int answer = Count(b + 1, k);
    Subtract(answer, Count(a, k));
    printf("%d\n", answer);
    return 0;
}
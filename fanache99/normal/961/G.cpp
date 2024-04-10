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

const int MAXN = 200000;
const int MOD = 1000000007;

int v[1 + MAXN];

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

int factorial[1 + MAXN], inverse[1 + MAXN];

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

void Precompute(int n) {
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    inverse[n] = RaiseToPower(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int Combinations(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int Stirling(int n, int k) {
    int answer = 0, sign = 1;
    for (int i = k; i >= 0; i--) {
        int add = (1LL * Combinations(k, i) * RaiseToPower(i, n)) % MOD;
        if (sign)
            Add(answer, add);
        else
            Subtract(answer, add);
        sign = 1 - sign;
    }
    answer = (1LL * answer * inverse[k]) % MOD;
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k, sum = 0;
    scanf("%d%d", &n, &k);
    Precompute(n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        Add(sum, x);
    }
    if (k == n) {
        printf("%d\n", sum);
        return 0;
    }
    if (k == 1) {
        sum = (1LL * sum * n) % MOD;
        printf("%d\n", sum);
        return 0;
    }
    int first = Stirling(n, k), second = (1LL * (n - 1) * Stirling(n - 1, k)) % MOD;
    sum = (1LL * sum * (first + second)) % MOD;
    printf("%d\n", sum);
    return 0;
}
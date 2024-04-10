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
const long long MOD = 1000000007;

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

int Combinations2(int n) {
    if (n % 2 == 0)
        return (1LL * (n / 2) * (n - 1)) % MOD;
    else
        return (1LL * n * ((n - 1) / 2)) % MOD;
}

int children[1 + MAXN], depth[1 + MAXN];
int answer[1 + 2 * MAXN], chains[1 + 2 * MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
        scanf("%d", &children[i]);
    depth[1] = 1;
    for (int i = 2; i <= n; i++)
        depth[i] = (1LL * depth[i - 1] * children[i - 1]) % MOD;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            chains[i + j] = (1LL * depth[i] * depth[j] + chains[i + j]) % MOD;
    int multiplier = 1;
    for (int i = 1; i < n; i++) {
        int divide = RaiseToPower(children[i], MOD - 2);
        for (int j = i + 1; j <= n; j++) {
            int add = (1LL * multiplier * depth[j]) % MOD;
            Add(answer[j - i], add);
            Subtract(chains[j - i + 2], (2LL * depth[j] * depth[i]) % MOD);
            depth[j] = (1LL * depth[j] * divide) % MOD;
        }
        divide = (1LL * divide * divide) % MOD;
        for (int j = 2; j <= 2 * (n - i); j++) {
            chains[j] = (1LL * chains[j + 2] * divide) % MOD;
            int add = (1LL * chains[j] * Combinations2(children[i])) % MOD;
            add = (1LL * add * multiplier) % MOD;
            Add(answer[j], add);
        }
        multiplier = (1LL * multiplier * children[i]) % MOD;
    }
    for (int i = 1; i <= 2 * n - 2; i++)
        printf("%d ", answer[i]);
    return 0;
}
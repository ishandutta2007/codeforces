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

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXVAL = 1 << 17;
const int MOD = 1000000007;

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

int fibonacci[MAXVAL];
int p[MAXVAL], q[MAXVAL], r[MAXVAL], t[MAXVAL];

void Precompute(int n) {
    fibonacci[1] = 1;
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1];
        Add(fibonacci[i], fibonacci[i - 2]);
    }
}

void FWHT(int data[], int dim) {
    for (int len = 1; 2 * len <= dim; len <<= 1) {
        for (int i = 0; i < dim; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int a = data[i + j];
                int b = data[i + j + len];

                data[i + j] = (a + b) % MOD;
                data[i + j + len] = (MOD + a - b) % MOD;
            }
        }
    }
}

void moddo(int &x) {
    while (x >= MOD)
        x -= MOD;
}

void to_transform(int data[], int dim) {
    int len, i, j;
    int u, v;

    for (len = 1; 2 * len <= dim; len <<= 1) {
        for (i = 0; i < dim; i += 2 * len) {
            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                data[i + j] = v;
                data[i + len + j] = (u + v);

                moddo(data[i + len + j]);
            }
        }
    }
}

void inv_transform(int data[], int dim) {
    int len, i, j;
    int u, v;

    for (len = 1; 2 * len <= dim; len <<= 1) {
        for (i = 0; i < dim; i += 2 * len) {
            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                data[i + j] = MOD - u + v;
                data[i + len + j] = u;

                moddo(data[i + j]);
            }
        }
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    Precompute(MAXVAL);
    int n = Read();
    for (int i = 1; i <= n; i++) {
        int x = Read();
        p[x]++;
        q[x]++;
        r[x]++;
    }
    FWHT(p, MAXVAL);
    for (int i = 0; i < MAXVAL; i++)
        p[i] = (1LL * p[i] * p[i]) % MOD;
    FWHT(p, MAXVAL);
    int inverse = RaiseToPower(MAXVAL, MOD - 2);
    for (int i = 0; i < MAXVAL; i++) {
        p[i] = (1LL * p[i] * inverse) % MOD;
        p[i] = (1LL * p[i] * fibonacci[i]) % MOD;
        q[i] = (1LL * q[i] * fibonacci[i]) % MOD;
    }
    to_transform(q, MAXVAL);
    to_transform(p, MAXVAL);
    for (int i = 0; i < MAXVAL; i++)
        p[i] = (1LL * p[i] * q[i]) % MOD;
    inv_transform(p, MAXVAL);
    for (int i = 0; i < MAXVAL; i++) {
        t[i] = (1LL * r[0] * r[i]) % MOD;
        for (int j = i; j; j = (i & (j - 1)))
            t[i] = (t[i] + 1LL * r[j] * r[i ^ j]) % MOD;
        t[i] = (1LL * t[i] * fibonacci[i]) % MOD;
    }
    to_transform(p, MAXVAL);
    to_transform(t, MAXVAL);
    for (int i = 0; i < MAXVAL; i++)
        p[i] = (1LL * p[i] * t[i]) % MOD;
    inv_transform(p, MAXVAL);
    int answer = 0;
    for (int i = 0; i < MAXVAL; i++)
        if (__builtin_popcount(i) == 1)
            Add(answer, p[i]);
    printf("%d\n", answer);
    return 0;
}
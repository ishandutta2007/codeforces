#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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

const int MAXVAL = 100000;
const int MAXD = 6;
const int MOD = 1000000007;

int low[1 + MAXVAL];

void Sieve(int n) {
    for (int i = 2; i <= n; i++)
        if (!low[i]) {
            low[i] = i;
            if (1LL * i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    if (!low[j])
                        low[j] = i;
        }
}

int factor[MAXD], factors, seen[1 + MAXVAL], power2[1 + MAXVAL];

void Decompose(int n) {
    factors = 0;
    while (n != 1) {
        int base = low[n];
        factor[factors] = base;
        factors++;
        while (low[n] == base)
            n /= base;
    }
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
    Sieve(MAXVAL);
    int n, answer = 0;
    scanf("%d", &n);
    power2[0] = 1;
    for (int i = 1; i <= n; i++)
        Add(power2[i], 2 * power2[i - 1]);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        Decompose(x);
        Add(answer, power2[i - 1]);
        for (int mask = 1; mask < (1 << factors); mask++) {
            int product = 1, bits = 0;
            for (int bit = 0; bit < factors; bit++)
                if (mask & (1 << bit)) {
                    product *= factor[bit];
                    bits++;
                }
            if (bits % 2)
                Subtract(answer, power2[seen[product]]);
            else
                Add(answer, power2[seen[product]]);
            seen[product]++;
        }
    }
    printf("%d\n", answer);
    return 0;
}
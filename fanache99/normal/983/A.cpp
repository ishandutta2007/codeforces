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

long long Gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long Bad(long long x, long long y) {
    long long h = Gcd(x, y), y0 = y / h;
    while (y0 != 1) {
        if (h == 1)
            return true;
        h = Gcd(h, y0);
        y0 = y0 / h;
    }
    return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        long long p, q, b;
        scanf("%I64d%I64d%I64d\n", &p, &q, &b);
        p %= q;
        if (p == 0) {
            printf("Finite\n");
            continue;
        }
        long long d = Gcd(p, q);
        p /= d;
        q /= d;
        if (Bad(b, q))
            printf("Infinite\n");
        else
            printf("Finite\n");
    }
    return 0;
}
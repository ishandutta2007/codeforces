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
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        long long x, n = 0, m = 0;
        scanf("%I64d", &x);
        if (x == 0) {
            printf("1 1\n");
            continue;
        }
        for (long long d = 1; d * d <= x && !n; d++)
            if (x % d == 0) {
                long long e = x / d;
                if ((e + d) % 2)
                    continue;
                long long a = (e + d) / 2, b = (e - d) / 2;
                long long left = 1, right = a, answer = a + 1;
                while (left <= right) {
                    long long middle = (left + right) / 2;
                    if (a / middle <= b) {
                        answer = middle;
                        right = middle - 1;
                    }
                    else
                        left = middle + 1;
                }
                if (answer != a + 1 && a / answer == b) {
                    n = a;
                    m = answer;
                }
            }
        if (!n)
            printf("-1\n");
        else
            printf("%I64d %I64d\n", n, m);
    }
    return 0;
}
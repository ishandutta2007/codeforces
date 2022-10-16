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

const int MAXN = 100000;
const int MOD = 1000000007;

int a[1 + MAXN], b[1 + MAXN], suffix[1 + MAXN + 1];

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

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, x = 0;
    scanf("%d%d", &n, &m);
    if (m == 1) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (!a[i])
            x++;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (!b[i])
            x++;
    }
    for (int i = n; i >= 1; i--)
        suffix[i] = suffix[i + 1] + (a[i] == 0) + (b[i] == 0);
    int denominator = RaiseToPower(m, x), numerator = 0, before = 0;
    for (int i = 1; i <= n; i++)
        if (!a[i] && !b[i]) {
            int here = (1LL * m * (m - 1) / 2) % MOD;
            Add(numerator, (1LL * RaiseToPower(m, before + suffix[i + 1]) * here) % MOD);
            before++;
        }
        else
            if (!a[i])
                Add(numerator, (1LL * RaiseToPower(m, before + suffix[i + 1]) * (m - b[i])) % MOD);
            else
                if (!b[i])
                    Add(numerator, (1LL * RaiseToPower(m, before + suffix[i + 1]) * (a[i] - 1)) % MOD);
                else
                    if (a[i] == b[i])
                        continue;
                    else {
                        if (a[i] > b[i])
                            Add(numerator, (1LL * RaiseToPower(m, before + suffix[i + 1])));
                        break;
                    }
    int answer = (1LL * numerator * RaiseToPower(denominator, MOD - 2)) % MOD;
    printf("%d\n", answer);
    return 0;
}
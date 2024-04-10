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
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        sign = -1;
        ch = Advance();
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

const int MAXD = 100;

long long v[1 + MAXD], d =0;

void Decompose(long long p, long long k) {
    while (p) {
        v[d] = p % k;
        d++;
        p /= k;
    }
}

long long Bad() {
    for (int i = 0; i < d; i++) {
        if (i % 2 && v[i] > 0)
            return i;
        if (i % 2 == 0 && v[i] < 0)
            return i;
    }
    return -1;
}

void Solve(long long x, long long k) {
    if (x % 2) {
        v[x + 1]++;
        v[x] = v[x] - k;
        x++;
        while (v[x] == k || v[x] == -k) {
            if (v[x] == k)
                v[x + 1]++;
            else
                v[x + 1]--;
            v[x] = 0;
            x++;
        }
        d = max(d, x + 1);
    }
    else {
        v[x + 1]--;
        v[x] = v[x] + x;
        x++;
        while (v[x] == k || v[x] == -k) {
            if (v[x] == k)
                v[x + 1]++;
            else
                v[x + 1]--;
            v[x] = 0;
            x++;
        }
        d = max(d, x + 1);
    }
}

long long Evaluate(long long k) {
    long long power = 1, answer = 0;
    for (int i = 0; i < d; i++) {
        answer += v[i] * power;
        power *= k;
    }
    return answer;
}

void Print() {
    printf("%I64d\n", d);
    for (int i = 0; i < d; i++)
        printf("%I64d ", abs(v[i]));
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long p, k;
    scanf("%I64d%I64d\n", &p, &k);
    Decompose(p, k);
    long long where = Bad();
    while (where != -1) {
        Solve(where, k);
        where = Bad();
    }
    assert(Evaluate(k) == p);
    Print();
    return 0;
}
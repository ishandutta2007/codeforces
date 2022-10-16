#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int MAXNODES = 262144;
const long long INF = 1000000000000000LL;
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

int v[1 + MAXN], c[1 + MAXN], seen[1 + MAXN];
long long best[1 + MAXN];

long long Solve(int a, int b, int n) {
    memset(best, 0, sizeof(best));
    memset(seen, 0, sizeof(seen));
    long long answer = 0, first = -INF, second = -INF, color = 0;
    for (int i = 1; i <= n; i++) {
        long long current = 1LL * v[i] * b;
        if (seen[c[i]])
            current = max(current, 1LL * v[i] * a + best[c[i]]);
        if (i - 1 - seen[c[i]])
            if (color == c[i])
                current = max(current, 1LL * v[i] * b + second);
            else
                current = max(current, 1LL * v[i] * b + first);
        answer = max(answer, current);
        seen[c[i]]++;
        if (seen[c[i]] == 1)
            best[c[i]] = current;
        else
            best[c[i]] = max(best[c[i]], current);
        if (color == c[i])
            first = max(first, current);
        else
            if (current > first) {
                second = first;
                first = current;
                color = c[i];
            }
            else
                second = max(second, current);
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), q = Read();
    for (int i = 1; i <= n; i++)
        v[i] = Read();
    for (int i = 1; i <= n; i++)
        c[i] = Read();
    for (int i = 1; i <= q; i++) {
        int a = Read(), b = Read();
        printf("%I64d\n", Solve(a, b, n));
    }
    return 0;
}
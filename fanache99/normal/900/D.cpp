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

const int MOD = 1000000007;

map<int, int> ways;

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

void Subtract(int &x, int y) {
    x -= y;
    if (x <= 0)
        x += MOD;
}

int Solve(int x) {
    if (ways[x])
        return ways[x];
    if (x == 1) {
        ways[x] = 1;
        return 1;
    }
    int answer = RaiseToPower(2, x - 1);
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0) {
            Subtract(answer, Solve(x / d));
            if (d != x / d)
                Subtract(answer, Solve(d));
        }
    Subtract(answer, 1);
    ways[x] = answer;
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int x, y;
    scanf("%d%d", &x, &y);
    if (y % x)
        printf("0\n");
    else
        printf("%d\n", Solve(y / x));
    return 0;
}
#include <fstream>
#include <iostream>
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
    int x, k, a, b;
    long long answer = 0;
    scanf("%d%d%d%d", &x, &k, &a, &b);
    if (k == 1) {
        printf("%I64d\n", 1LL * a * (x - 1));
        return 0;
    }
    while (x != 1) {
        if (x % k) {
            answer += 1LL * a * (x % k);
            x -= x % k;
            if (x == 0) {
                answer -= a;
                x++;
                }
            continue;
        }
        answer += min(1LL * b, 1LL * a * (x - x / k));
        x /= k;
    }
    printf("%I64d\n", answer);
    return 0;
}
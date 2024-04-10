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

const int MAXN = 100000;
const int INF = 1000000000;

int a[1 + MAXN];
char b[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d ", &a[i]);
    scanf("%s", b + 1);
    int l1 = -INF, l2 = INF, r1 = -INF, r2 = INF;
    for (int i = 5; i <= n; i++) {
        if (b[i - 1] == '1' && b[i - 2] == '1' && b[i - 3] == '1' && b[i - 4] == '1') {
            if (b[i] == '0')
                r2 = min(r2, min(min(min(a[i], a[i - 1]), a[i - 2]), min(a[i - 3], a[i - 4])) - 1);
            else
                r1 = max(r1, min(min(min(a[i], a[i - 1]), a[i - 2]), min(a[i - 3], a[i - 4])));
            continue;
        }
        if (b[i - 1] == '0' && b[i - 2] == '0' && b[i - 3] == '0' && b[i - 4] == '0') {
            if (b[i] == '1')
                l1 = max(l1, max(max(max(a[i], a[i - 1]), a[i - 2]), max(a[i - 3], a[i - 4])) + 1);
            else
                l2 = min(l2, max(max(max(a[i], a[i - 1]), a[i - 2]), max(a[i - 3], a[i - 4])));
            continue;
        }
    }
    printf("%d %d\n", l1, r2);
    return 0;
}
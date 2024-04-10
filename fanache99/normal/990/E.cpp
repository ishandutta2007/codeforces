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

const int MAXN = 1000000;
const long long INF = 1000000000000000000LL;

bool out[1 + MAXN];
int toLeft[1 + MAXN];

int Cover(int n, int l) {
    int answer = 0, where = 0;
    while (1) {
        answer++;
        where += l;
        if (where >= n)
            break;
        where = toLeft[where];
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read(), k = Read();
    for (int i = 1; i <= m; i++) {
        int x = Read();
        out[x] = true;
    }
    if (out[0]) {
        printf("-1\n");
        return 0;
    }
    int start = 1;
    for (int i = 0; i <= n - 1; i++) {
        if (!out[i])
            toLeft[i] = i;
        else
            toLeft[i] = toLeft[i - 1];
        start = max(start, i - toLeft[i] + 1);
    }
    if (start > k) {
        printf("-1\n");
        return 0;
    }
    long long answer = INF;
    for (int i = 1; i <= k; i++) {
        int cost = Read();
        if (i < start)
            continue;
        answer = min(answer, 1LL * cost * Cover(n, i));
    }
    printf("%I64d\n", answer);
    return 0;
}
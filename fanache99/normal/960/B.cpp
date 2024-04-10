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

const int MAXN = 1000;

int a[1 + MAXN], b[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= k1; i++) {
        int best = 1;
        for (int j = 2; j <= n; j++)
            if (abs(a[j] - b[j]) > abs(a[best] - b[best]))
                best = j;
        if (a[best] > b[best])
            a[best]--;
        else
            a[best]++;
    }
    for (int i = 1; i <= k2; i++) {
        int best = 1;
        for (int j = 2; j <= n; j++)
            if (abs(a[j] - b[j]) > abs(a[best] - b[best]))
                best = j;
        if (a[best] > b[best])
            b[best]++;
        else
            b[best]--;
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
        answer += 1LL * (a[i] - b[i]) * (a[i] - b[i]);
    printf("%I64d\n", answer);
    return 0;
}
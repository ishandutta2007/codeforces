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

const int MAXN = 50000;

long long v[1 + 2 * MAXN];
long long s[1 + 2 * MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    n /= 2;
    for (int i = 2; i <= 2 * n; i += 2) {
        scanf("%I64d", &v[i]);
        for (long long d = 1; d * d < v[i]; d++)
            if (v[i] % d == 0 && (d + v[i] / d) % 2 == 0) {
                long long b = (d + v[i] / d) / 2, a = (v[i] / d - d) / 2;
                if (a > s[i - 2] && (s[i] == 0 || s[i] > b)) {
                    s[i] = b;
                    s[i - 1] = a;
                }
            }
        if (!s[i]) {
            printf("No\n");
            return 0;
        }
    }
    for (int i = 1; i < 2 * n; i += 2)
        v[i] = s[i] * s[i] - s[i - 1] * s[i - 1];
    printf("Yes\n");
    for (int i = 1; i <= 2 * n; i++)
        printf("%I64d ", v[i]);
    return 0;
}
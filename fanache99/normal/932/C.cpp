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
    while (!isdigit(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 1000000;

int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int i = 1, k = 0;
    while (i <= n)
        if ((n - i + 1) % b == 0) {
            for (int j = i + 1; j <= i + b - 1; j++) {
                k++;
                v[k] = j;
            }
            k++;
            v[k] = i;
            i += b;
        }
        else {
            if (i + a - 1 > n) {
                printf("-1\n");
                return 0;
            }
            for (int j = i + 1; j <= i + a - 1; j++) {
                k++;
                v[k] = j;
            }
            k++;
            v[k] = i;
            i += a;
        }
    for (int i = 1; i <= n; i++)
        printf("%d ", v[i]);
    return 0;
}
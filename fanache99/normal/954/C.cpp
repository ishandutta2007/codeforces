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

const int MAXN = 200000;

int v[1 + MAXN];

bool Ok(int a, int b, int y) {
    if (a > b)
        swap(a, b);
    if (a % y == 0)
        return false;
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i < n; i++)
        if (abs(v[i] - v[i + 1]) == 0) {
            printf("NO\n");
            return 0;
        }
    int y = 0;
    for (int i = 1; i < n; i++)
        if (abs(v[i] - v[i + 1]) > 1)
            y = abs(v[i] - v[i + 1]);
    if (!y) {
        printf("YES\n1000000000 1\n");
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (abs(v[i] - v[i + 1]) > 1 && abs(v[i] - v[i + 1]) != y) {
            printf("NO\n");
            return 0;
        }
        if (abs(v[i] - v[i + 1]) == 1 && !Ok(v[i], v[i + 1], y)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n1000000000 %d\n", y);
    return 0;
}
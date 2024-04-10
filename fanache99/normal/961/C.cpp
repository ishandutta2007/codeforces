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

const int MAXN = 100;

int a[4][1 + MAXN][1 + MAXN], p[4], answer;
char s[1 + MAXN];
int b[1 + 2 * MAXN][1 + 2 * MAXN];

void Try(int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            b[i][j] = a[p[0]][i][j];
            b[i][n + j] = a[p[1]][i][j];
            b[i + n][j] = a[p[2]][i][j];
            b[i + n][j + n] = a[p[3]][i][j];
        }
    int first = 0, second = 0;
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 1; j <= 2 * n; j++) {
            int x = (i + j) % 2;
            if (b[i][j] != x)
                first++;
            else
                second++;
        }
    answer = min(answer, min(first, second));
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for (int k = 0; k < 4; k++) {
        for (int i = 1; i <= n; i++) {
            scanf("%s", s + 1);
            for (int j = 1; j <= n; j++)
                a[k][i][j] = s[j] - '0';
        }
        p[k] = k;
    }
    answer = 4 * n * n;
    Try(n);
    while (next_permutation(p, p + 4))
        Try(n);
    printf("%d\n", answer);
    return 0;
}
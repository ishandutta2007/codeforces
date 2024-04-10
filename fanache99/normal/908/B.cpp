//#include <iostream>
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

const int MAXN = 50;
const int MAXL = 100;

char a[1 + MAXN][1 + MAXN], s[1 + MAXL];
int p[4] = {0, 1, 2, 3}, ls, cs, lf, cf;
int line[4] = {0, 1, 0, -1};
int column[4] = {1, 0, -1, 0};

int Check(int n, int m, int q) {
    int l = ls, c = cs;
    for (int i = 1; i <= q; i++) {
        int l0 = l + line[p[s[i] - '0']], c0 = c + column[p[s[i] - '0']];
        if (l0 < 1 || c0 < 1 || l0 > n || c0 > m)
            return 0;
        if (a[l0][c0] == '#')
            return 0;
        if (l0 == lf && c0 == cf)
            return 1;
        l = l0;
        c = c0;
    }
    return 0;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s\n", a[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'S') {
                ls = i;
                cs = j;
                a[i][j] = '.';
            }
            if (a[i][j] == 'E') {
                lf = i;
                cf = j;
                a[i][j] = '.';
            }
        }
    }
    scanf("%s", s + 1);
    int l = strlen(s + 1), answer = 0;
    answer += Check(n, m, l);
    while (next_permutation(p, p + 4))
        answer += Check(n, m, l);
    printf("%d\n", answer);
    return 0;
}
#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

const int SIZE = 1 << 17;
const int MAXN = 1000;

char buffer[SIZE];
int pointer = SIZE;

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

char a[1 + MAXN][1 + MAXN];
int line[4] = {1, 0, -1, 0};
int column[4] = {0, 1, 0, -1};
bool seen[3][4][1 + MAXN][1 + MAXN];
queue<pair<pair<int, int>, pair<int, int> > > Queue;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, ls, cs, lf, cf;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'S') {
                ls = i;
                cs = j;
            }
            else
                if (a[i][j] == 'T') {
                    lf = i;
                    cf = j;
                }
    }
    for (int d = 0; d < 4; d++) {
        seen[0][d][ls][cs] = true;
        Queue.push(make_pair(make_pair(ls, cs), make_pair(d, 0)));
    }
    while (!Queue.empty()) {
        int l = Queue.front().first.first, c = Queue.front().first.second, d = Queue.front().second.first, k = Queue.front().second.second;
        Queue.pop();
        for (int i = 0; i < 4; i++)
            if (i != (d + 2) % 4 && (k < 2 || i == d)) {
                int l0 = l + line[i], c0 = c + column[i], k0 = k;
                if (i != d)
                    k0++;
                if (l0 <= n && l0 > 0 && c0 <= m && c0 > 0 && a[l0][c0] != '*' && !seen[k0][i][l0][c0]) {
                    seen[k0][i][l0][c0] = true;
                    Queue.push(make_pair(make_pair(l0, c0), make_pair(i, k0)));
                }
            }
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            if (seen[i][j][lf][cf]) {
                printf("YES\n");
                return 0;
            }
    printf("NO\n");
    return  0;
}
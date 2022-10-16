#include <bits/stdc++.h>

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

const int MAXN = 100;

char a[1 + MAXN][1 + MAXN];
int n;
int dx[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};

void DFS(int x, int y, char ch) {
    a[x][y] = ch;
    for (int i = 0; i < 8; i++) {
        int x0 = x + dx[i], y0 = y + dy[i];
        if (x0 >= 1 && y0 >= 1 && x0 <= n && y0 <= n && !a[x0][y0])
            DFS(x0, y0, 'W' + 'B'- ch);
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++, printf("\n"))
        for (int j = 1; j <= n; j++) {
            if (!a[i][j])
                DFS(i, j, 'W');
            printf("%c", a[i][j]);
        }
    return 0;
}
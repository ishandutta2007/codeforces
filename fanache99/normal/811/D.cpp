#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

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

const int MAXN = 100;

char a[1 + MAXN][1 + MAXN];
int line[4] = {1, 0, -1, 0};
int column[4] = {0, 1, 0, -1};
int letter[4] = {'D', 'R', 'U', 'L'};
pair<int, int> dad[1 + MAXN][1 + MAXN];
vector<pair<int, int> > answer;
int best[1 + MAXN][1 + MAXN];

void Lee(int n, int m, int x, int y) {
    queue<pair<int, int> > Queue;
    Queue.push(make_pair(x, y));
    best[x][y] = 1;
    while (!Queue.empty()) {
        int l = Queue.front().first, c = Queue.front().second;
        Queue.pop();
        for (int i = 0; i < 4; i++) {
            int l0 = l + line[i], c0 = c + column[i];
            if (l0 && c0 && l0 <= n && c0 <= m && !best[l0][c0] && a[l0][c0] != '*') {
                Queue.push(make_pair(l0, c0));
                best[l0][c0] = best[l][c] + 1;
                dad[l0][c0] = make_pair(l, c);
            }
        }
    }
    bool found = false;
    for (int i = 1; i <= n && !found; i++)
        for (int j = 1; j <= m && !found; j++)
            if (a[i][j] == 'F') {
                answer.push_back(make_pair(i, j));
                while (i != x || j != y) {
                    int i0 = dad[i][j].first, j0 = dad[i][j].second;
                    answer.push_back(make_pair(i0, j0));
                    i = i0;
                    j = j0;
                }
                found = true;
            }
    for (int i = answer.size() - 1; i > 0; i--) {
        int l = answer[i].first, c = answer[i].second, l0 = answer[i - 1].first, c0 = answer[i - 1].second;
        for (int j = 0; j < 4; j++)
            if (l0 == l + line[j] && c0 == c + column[j]) {
                printf("%c\n", letter[j]);
                fflush(stdout);
                scanf("%d%d", &x, &y);
                break;
            }
    }

}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", a[i] + 1);
    if (a[1][1] == 'F')
        return 0;
    if (n == 1) {
        char ch = 'R';
        printf("%c\n", ch);
        fflush(stdout);
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 1 && y == 1)
            ch = 'L';
        while (a[x][y] != 'F') {
            printf("%c\n", ch);
            fflush(stdout);
            scanf("%d%d", &x, &y);
        }
        return 0;
    }
    if (m == 1) {
        char ch = 'D';
        printf("%c\n", ch);
        fflush(stdout);
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 1 && y == 1)
            ch = 'U';
        while (a[x][y] != 'F') {
            printf("%c\n", ch);
            fflush(stdout);
            scanf("%d%d", &x, &y);
        }
        return 0;
    }
    int x = 1, y = 1;
    if (a[1][2] != '*') {
        printf("%c\n", letter[1]);
        fflush(stdout);
        scanf("%d%d", &x, &y);
        if (x == 1 && y == 1)
            swap(letter[1], letter[3]);
        else {
            if (a[1][2] == 'F')
                return 0;
            printf("%c\n", letter[3]);
            fflush(stdout);
            scanf("%d%d", &x, &y);
        }
        while (a[x + 1][y] == '*' && a[x][y] != 'F') {
            printf("%c\n", letter[1]);
            fflush(stdout);
            scanf("%d%d", &x, &y);
        }
        if (a[x][y] == 'F')
            return 0;
        printf("%c\n", letter[0]);
        fflush(stdout);
        scanf("%d%d", &x, &y);
        if (x == 1)
            swap(letter[0], letter[2]);
        else {
            if (a[x][y] == 'F')
                return 0;
            printf("%c\n", letter[2]);
            fflush(stdout);
            scanf("%d%d", &x, &y);
        }
        Lee(n, m, x, y);
    }
    else {
        printf("%c\n", letter[0]);
        fflush(stdout);
        scanf("%d%d", &x, &y);
        if (x == 1 && y == 1)
            swap(letter[0], letter[2]);
        else {
            if (a[2][1] == 'F')
                return 0;
            printf("%c\n", letter[2]);
            fflush(stdout);
            scanf("%d%d", &x, &y);
        }
        while (a[x][y + 1] == '*' && a[x][y] != 'F') {
            printf("%c\n", letter[0]);
            fflush(stdout);
            scanf("%d%d", &x, &y);
        }
        if (a[x][y] == 'F')
            return 0;
        printf("%c\n", letter[1]);
        fflush(stdout);
        scanf("%d%d", &x, &y);
        if (y == 1)
            swap(letter[1], letter[3]);
        else {
            if (a[x][y] == 'F')
                return 0;
            printf("%c\n", letter[3]);
            fflush(stdout);
            scanf("%d%d", &x, &y);
        }
        Lee(n, m, x, y);
    }
    return 0;
}
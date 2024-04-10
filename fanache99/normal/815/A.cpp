#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <map>

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
const int INF = 1000000000;

int a[1 + MAXN][1 + MAXN], temp[1 + MAXN][1 + MAXN], row[1 + MAXN], column[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    int answer = 0, type;
    if (n <= m) {
        type = 1;
        int smallest = INF;
        for (int i = 1; i <= m; i++)
            smallest = min(smallest, a[1][i]);
        answer = smallest;
        for (int i = 1; i <= m; i++)
            a[1][i] -= smallest;
    }
    else {
        type = 2;
        int smallest = INF;
        for (int i = 1; i <= n; i++)
            smallest = min(smallest, a[i][1]);
        answer = smallest;
        for (int i = 1; i <= n; i++)
            a[i][1] -= smallest;
    }
    int l, c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!a[i][j]) {
                l = i;
                c = j;
                break;
            }
    int add = answer;
    for (int i = 1; i <= n; i++) {
        row[i] = a[i][c];
        answer += row[i];
    }
    for (int i = 1; i <= m; i++) {
        column[i] = a[l][i];
        answer += column[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            a[i][j] -= row[i] + column[j];
            if (a[i][j]) {
                printf("-1\n");
                return 0;
            }
        }
    printf("%d\n", answer);
    if (type == 1)
        for (int i = 1; i <= add; i++)
            printf("row 1\n");
    else
        for (int i = 1; i <= add; i++)
            printf("col 1\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= row[i]; j++)
            printf("row %d\n", i);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= column[i]; j++)
            printf("col %d\n", i);
    return 0;
}
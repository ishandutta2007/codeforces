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

void Even(int l, int m) {
    for (int i = 2; i <= m; i += 2)
        printf("%d ", (l - 1) * m + i);
}

void Odd(int l, int m) {
    for (int i = 1; i <= m; i += 2)
        printf("%d ", (l - 1) * m + i);
}

vector<vector<int> > a, b;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    bool swapped = false;
    scanf("%d%d", &n, &m);
    a.resize(1 + n);
    for (int i = 1; i <= n; i++) {
        a[i].resize(1 + m);
        for (int j = 1; j <= m; j++)
            a[i][j] = (i - 1) * m + j;
    }
    b.resize(1 + n);
    for (int i = 1; i <= n; i++)
        b[i].resize(1 + m);
    if (n == 1 && m == 1) {
        printf("YES\n1\n");
        return 0;
    }
    if ((n <= 2 && m <= 3) || (n <= 3 && m <= 2)) {
        printf("NO\n");
        return 0;
    }
    if (n == 3 && m == 3) {
        printf("YES\n5 1 9\n3 8 4\n7 6 2\n");
        return 0;
    }
    printf("YES\n");
    if (m == 4) {
        for (int i = 1; i <= n; i++)
            if (i % 2)
                printf("%d %d %d %d\n", (i - 1) * m + 2, (i - 1) * m + 4, (i - 1) * m + 1, (i - 1) * m + 3);
            else
                printf("%d %d %d %d\n", (i - 1) * m + 3, (i - 1) * m + 1, (i - 1) * m + 4, (i - 1) * m + 2);
        return 0;
    }
    if (m > 4) {
        for (int i = 1; i <= n; i++, printf("\n"))
            if (i % 2) {
                Even(i, m);
                Odd(i, m);
            }
            else {
                Odd(i, m);
                Even(i, m);
            }
        return 0;
    }
    if (n == 4) {
        for (int j = 1; j <= m; j++)
            if (j % 2) {
                b[1][j] = a[2][j];
                b[2][j] = a[4][j];
                b[3][j] = a[1][j];
                b[4][j] = a[3][j];
            }
            else {
                b[1][j] = a[3][j];
                b[2][j] = a[1][j];
                b[3][j] = a[4][j];
                b[4][j] = a[2][j];
            }
    }
    else {
        for (int j = 1; j <= m; j++)
            if (j % 2) {
                int x = 0;
                for (int i = 2; i <= n; i += 2)
                    b[++x][j] = a[i][j];
                for (int i = 1; i <= n; i += 2)
                    b[++x][j] = a[i][j];
            }
            else {
                int x = 0;
                for (int i = 1; i <= n; i += 2)
                    b[++x][j] = a[i][j];
                for (int i = 2; i <= n; i += 2)
                    b[++x][j] = a[i][j];
            }
    }
    for (int i = 1; i <= n; i++, printf("\n"))
        for (int j = 1; j <= m; j++)
            printf("%d ", b[i][j]);
    return 0;
}
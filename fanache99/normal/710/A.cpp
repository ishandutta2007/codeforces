#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


int a[12][12];

void Precompute() {
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
                a[i][j] = 8;
    a[1][1] = a[1][8] = a[8][1] = a[8][8] = 3;
    for (int i = 2; i <= 7; i++)
        a[1][i] = a[i][1] = a[8][i] = a[i][8] = 5;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    char line, column;
    Precompute();
    scanf("%c%c", &line, &column);
    line = line - 'a' + 1;
    column = column - '0';
    printf("%d", a[line][column]);
    return 0;
}
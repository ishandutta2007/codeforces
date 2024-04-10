#include <stdio.h>
using namespace std;

int n, a[50][50];

bool check(int i, int j) {
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < n; ++y)
            if (a[i][x] + a[y][j] == a[i][j])
                return true;
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] != 1 && !check(i, j)) {
                printf("No");
                return 0;
            }
    printf("Yes");
    return 0;
}
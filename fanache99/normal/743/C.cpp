#include <cstdio>
//#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("-1\n");
        return 0;
    }
    printf("%d %d %d\n", n, n + 1, n * (n + 1));
    return 0;
}
#include <cstdio>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int k, r;
    scanf("%d%d", &k, &r);
    for (int i = 1; i <= 9; i++)
        if ((k * i) % 10 == r || (k * i) % 10 == 0) {
            printf("%d\n", i);
            return 0;
        }
    printf("10\n");
    return 0;
}
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k, a, b;
    scanf("%d%d%d%d", &n, &k, &a, &b);
    bool inverse = false;
    if (a > b) {
        swap(a, b);
        inverse = true;
    }
    if (1LL * (a + 1) * k < b) {
        printf("NO\n");
        return 0;
    }
    int g = b / k;
    if (b % k != 0)
        g++;
    a = a - g + 1;
    for (int i = 1; i < g; i++) {
        for (int j = 1; j <= k; j++, b--)
            if (inverse)
                printf("G");
            else
                printf("B");
        if (inverse)
            printf("B");
        else
            printf("G");
        for (int j = 2; j <= k && a; j++, a--)
            if (inverse)
                printf("B");
            else
                printf("G");
    }
    for (int i = 1; i <= b; i++)
        if (inverse)
            printf("G");
        else
            printf("B");
    for (int i = 1; i <= a; i++)
        if (inverse)
            printf("B");
        else
            printf("G");
    return 0;
}
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, first = -1, second = -1, third = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (first == -1)
            first = x;
        else
            if (first != x)
                if (second == -1)
                    second = x;
                else
                    if (x != second)
                        if (third == -1)
                            third = x;
                        else
                            if (third != x) {
                                printf("NO\n");
                                return 0;
                            }
    }
    if (third == -1 || second == -1) {
        printf("YES\n");
        return 0;
    }
    int a = first, b = second, c = third;
    first = min(a, min(b, c));
    third = max(a, max(b, c));
    second = a + b + c - first - third;
    if (second - first != third - second) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}
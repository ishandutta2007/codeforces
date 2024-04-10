#include <cstdio>

const int N = 1000;

int n, a[N];

int main() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int a;
            scanf("%d", &a);
            if (i == j) {
                sum ^= a;
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q --) {
        int t;
        scanf("%d", &t);
        if (t == 3) {
            printf("%d", sum % 2);
        } else {
            scanf("%*d");
            sum ^= 1;
        }
    }
    puts("");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool flag = 0;
        for (int i = 1; i < 30; i++) if (!(n % (1 << i))) {
            int j = n / (1 << i), k = sqrt(j) - 1;
            while ((k + 1) * (k + 1) <= j) k++;
            if (k * k == j) flag = 1;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector<int> V = {1};
        while (3LL * V.back() <= 1000000000) V.push_back(3 * V.back());
        if (V.size() < n) { puts("NO"); continue; }
        puts("YES");
        for (int i = 0; i < n; i++) printf("%d ", V[i]);
        putchar('\n');
    }
    return 0;
}
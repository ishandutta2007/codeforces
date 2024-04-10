#include <bits/stdc++.h>
using namespace std;

int n, p;

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= 50; i++) {
        long long m = n - 1LL * i * p;
        if (__builtin_popcountll(m) <= i && m >= i) printf("%d\n", i), exit(0);
    }
    puts("-1");
    return 0;
}
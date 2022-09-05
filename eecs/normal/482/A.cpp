#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, lst;

int main() {
    scanf("%d %d", &n, &K);
    int l = 1, r = n;
    for (int i = 1; i <= K; i++) {
        if (i & 1) printf("%d ", lst = l++);
        else printf("%d ", lst = r--);
    }
    for (int i = K + 1; i <= n; i++) {
        if (K & 1) printf("%d ", ++lst);
        else printf("%d ", --lst);
    }
    return 0;
}
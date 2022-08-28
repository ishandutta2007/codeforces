#include <bits/stdc++.h>
using namespace std;
int s[100010], n, q;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", s + i), s[i] += s[i - 1];
    scanf("%d", &q);
    for(int i = 1, l, r; i <= q; i++) scanf("%d%d", &l, &r), printf("%d\n", (s[r] - s[l - 1]) / 10);
    return 0;
}
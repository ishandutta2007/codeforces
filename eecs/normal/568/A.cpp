#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000010;
int p, q;
bool chk1[maxn], chk2[maxn];

int main() {
    scanf("%d %d", &p, &q);
    fill(chk1 + 2, chk1 + maxn, 1);
    int c1 = 0, c2 = 0, lst = -1;
    for (int i = 1; i < maxn; i++) {
        int j = i, k = 0;
        while (j) k = k * 10 + j % 10, j /= 10;
        if (i == k) chk2[i] = 1;
        if (chk1[i]) {
            for (int j = i + i; j < maxn; j += i) chk1[j] = 0;
        }
        c1 += chk1[i], c2 += chk2[i];
        if (c1 <= 1LL * p * c2 / q) lst = i;
    }
    if (!~lst) puts("Palindromic tree is better than splay tree");
    else printf("%d\n", lst);
    return 0;
}
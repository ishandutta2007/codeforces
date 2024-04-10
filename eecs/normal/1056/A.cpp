#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, r;
bitset<maxn> b;

int main() {
    scanf("%d", &n);
    b.set();
    while (n--) {
        int r; scanf("%d", &r);
        bitset<maxn> a;
        while (r--) {
            int x; scanf("%d", &x);
            a[x] = 1;
        }
        b &= a;
    }
    for (int i = 1; i <= 100; i++) {
        if (b[i]) printf("%d ", i);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, f, xors, sg[maxn], mn[maxn];
bitset<maxn> b, ban[100];

int main() {
    scanf("%d %d", &n, &f);
    for (int i = 2; i < maxn; i++) if (!mn[i]) {
        for (int j = i; j < maxn; j += i) mn[j] = i;
    }
    for (int i = 2; i < maxn; i++) if (i ^ f) {
        if (i == mn[i] || mn[i / mn[i]] == i / mn[i]) b.set(i);
    }
    ban[0] = b;
    for (int i = 1; i < maxn; i++) {
        while (ban[sg[i]][i]) sg[i]++;
        ban[sg[i]] |= b << i;
    }
    while (n--) {
        int b, w, r;
        scanf("%d %d %d", &b, &w, &r);
        xors ^= sg[w - b - 1] ^ sg[r - w - 1];
    }
    puts(xors ? "Alice\nBob" : "Bob\nAlice");
    return 0;
}
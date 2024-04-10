#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 12;
int K, a[maxn], b[maxn], c[maxn], cnt[maxn];
mt19937 rnd(time(0));

int main() {
    scanf("%d", &K);
    for (int i = 0; i < 1 << K; i++) {
        scanf("%d", &a[i]);
        b[i] = c[i] = i, cnt[a[i] ^ b[i]]++;
    }
    if (accumulate(a, a + (1 << K), 0, bit_xor<>())) puts("Fou"), exit(0);
    puts("Shi");
    while (1) {
        int p = min_element(cnt, cnt + (1 << K)) - cnt;
        if (cnt[p]) break;
        int i = rnd() % (1 << K);
        while (cnt[a[i] ^ b[i]] == 1) i = rnd() % (1 << K);
        int j = c[a[i] ^ p];
        cnt[a[i] ^ b[i]]--, cnt[a[j] ^ b[j]]--;
        swap(b[i], b[j]);
        cnt[a[i] ^ b[i]]++, cnt[a[j] ^ b[j]]++;
        c[b[i]] = i, c[b[j]] = j;
    }
    for (int i = 0; i < 1 << K; i++) {
        printf("%d ", b[i]);
    }
    putchar('\n');
    for (int i = 0; i < 1 << K; i++) {
        printf("%d ", a[i] ^ b[i]);
    }
    putchar('\n');
    return 0;
}
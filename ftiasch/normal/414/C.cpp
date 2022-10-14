#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 20;

int n, a[1 << N], buffer[1 << N];
long long level[N + 1][2];

void prepare(int depth, int l, int r) {
    if (r - l >= 2) {
        int m = l + r >> 1;
        prepare(depth - 1, l, m);
        prepare(depth - 1, m, r);
        int i = l;
        int j = m;
        int k = i;
        while (i < m || j < r) {
            if (i < m && (j == r || a[i] <= a[j])) {
                buffer[k ++] = a[i ++];
                level[depth][0] += j - m;
            } else {
                buffer[k ++] = a[j ++];
            }
        }
        i = l;
        j = m;
        k = i;
        while (i < m || j < r) {
            if (i < m && (j == r || a[i] < a[j])) {
                buffer[k ++] = a[i ++];
            } else {
                buffer[k ++] = a[j ++];
                level[depth][1] += i - l;
            }
        }
        for (int i = l; i < r; ++ i) {
            a[i] = buffer[i];
        }
    }
}

int status[N + 1];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 1 << n; ++ i) {
        scanf("%d", a + i);
    }
    memset(level, 0, sizeof(level));
    prepare(n, 0, 1 << n);
    memset(status, 0, sizeof(status));
    int m;
    scanf("%d", &m);
    while (m --) {
        int q;
        scanf("%d", &q);
        long long answer = 0;
        for (int i = 0; i <= q; ++ i) {
            status[i] ^= 1;
        }
        for (int i = 0; i <= n; ++ i) {
            answer += level[i][status[i]];
        }
        printf("%I64d\n", answer);
    }
    return 0;
}
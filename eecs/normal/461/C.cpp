#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q, num[maxn];

namespace BIT {
int c[maxn];

void add(int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}
}  // namespace BIT

int main() {
    scanf("%d %d", &n, &q);
    fill(num + 1, num + n + 1, 1);
    for (int i = 1; i <= n; i++) BIT::add(i, 1);
    int L = 1, R = n;
    bool flip = 0;
    int len = R - L + 1;
    while (q--) {
        int op, p, q;
        scanf("%d %d", &op, &p);
        if (op == 1) len = max(p, len - p);
        p += L - 1;
        if (op == 1) {
            if (flip) {
                if (p >= R) continue;
                p = L + R - 1 - p;
                if (p - L + 1 <= R - p) {
                    for (int i = p; i >= L; i--) {
                        num[2 * p - i + 1] += num[i];
                        BIT::add(2 * p - i + 1, num[i]);
                    }
                    L = p + 1, flip ^= 1;
                } else {
                    for (int i = p + 1; i <= R; i++) {
                        num[2 * p - i + 1] += num[i];
                        BIT::add(2 * p - i + 1, num[i]);
                    }
                    R = p;
                }
            } else {
                if (p - L + 1 <= R - p) {
                    for (int i = p; i >= L; i--) {
                        num[2 * p - i + 1] += num[i];
                        BIT::add(2 * p - i + 1, num[i]);
                    }
                    L = p + 1;
                } else {
                    for (int i = p + 1; i <= R; i++) {
                        num[2 * p - i + 1] += num[i];
                        BIT::add(2 * p - i + 1, num[i]);
                    }
                    R = p, flip ^= 1;
                }
            }
        } else {
            scanf("%d", &q);
            p++, q += L;
            if (flip) p = L + R + 1 - p, q = L + R + 1 - q;
            if (p > q) swap(p, q);
            printf("%d\n", BIT::sum(q - 1) - BIT::sum(p - 1));
        }
        assert(R - L + 1 == len);
    }
    return 0;
}
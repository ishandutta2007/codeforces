#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q;
char s[maxn], t[maxn];
bitset<maxn> b[26], c;

int main() {
    scanf("%s %d", s + 1, &q), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        b[s[i] - 'a'][i] = 1;
    }
    while (q--) {
        int op, l, r;
        scanf("%d %d", &op, &l);
        if (op == 1) {
            scanf("%s", t);
            b[s[l] - 'a'][l] = 0;
            s[l] = t[0], b[s[l] - 'a'][l] = 1;
        } else {
            scanf("%d %s", &r, t), c.set();
            int m = strlen(t);
            for (int i = 0; i < m; i++) {
                c &= (b[t[i] - 'a'] >> i);
            }
            r = r - m + 1;
            if (r < l) { puts("0"); continue; }
            c >>= l, c <<= l;
            c <<= maxn - r - 1, c >>= maxn - r - 1;
            printf("%d\n", c.count());
        }
    }
    return 0;
}
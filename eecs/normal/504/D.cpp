#include <bits/stdc++.h>
using namespace std;

const int maxn = 2110;
int m;
bitset<maxn> b[maxn], a[maxn], c, cur;

int main() {
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        c.reset();
        long long t = 1LL << 50;
        string s; cin >> s;
        reverse(s.begin(), s.end());
        int len = 0, m = s.size();
        while (m) {
            long long cur = 0;
            for (int i = m - 1; ~i; i--) {
                cur = cur * 10 + s[i] - '0';
                s[i] = cur / t + '0', cur %= t;
            }
            for (int i = 0; i < 50; i++) {
                c[len++] = cur & 1, cur >>= 1;
            }
            while (m && s[m - 1] == '0') m--;
        }
        bool flag = 0;
        cur.reset(), cur[i] = 1;
        for (int j = 2100; ~j; j--) if (c[j]) {
            if (a[j].any()) {
                c ^= a[j], cur ^= b[j];
                if (c.none()) {
                    vector<int> V;
                    for (int k = 0; k < i; k++) if (cur[k]) V.push_back(k);
                    printf("%d", V.size());
                    for (int x : V) printf(" %d", x);
                    putchar('\n'), flag = 1; break;
                }
            } else {
                b[j] = cur, a[j] = c; break;
            }
        }
        if (!flag) puts("0");
    }
    return 0;
}
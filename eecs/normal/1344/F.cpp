#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, K, tot, x[maxn], pos[maxn];
bitset<maxn> cur[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cur[i].set(i);
        cur[i + n].set(i + n);
    }
    while (K--) {
        int k; string op;
        cin >> op >> k;
        if (op == "mix") {
            while (k--) {
                int x; cin >> x;
                b[tot + 1] ^= cur[x];
                b[tot + 2] ^= cur[x + n];
            }
            cin >> op;
            if (op == "R" || op == "B") b[tot + 1].set(n << 1 | 1);
            if (op == "Y" || op == "B") b[tot + 2].set(n << 1 | 1);
            tot += 2;
        } else if (op == "RY") { // swap(a[i], b[i])
            while (k--) {
                int x; cin >> x;
                swap(cur[x], cur[x + n]);
            }
        } else if (op == "RB") { // b[i] <- a[i] xor b[i]
            while (k--) {
                int x; cin >> x;
                cur[x + n] ^= cur[x];
            }
        } else { // a[i] <- a[i] xor b[i]
            while (k--) {
                int x; cin >> x;
                cur[x] ^= cur[x + n];
            }
        }
    }
    int r = 1;
    for (int i = 1; i <= n + n; i++) {
        for (int j = r; j <= tot; j++) if (b[j].test(i)) {
            swap(b[r], b[j]); break;
        }
        if (!b[r].test(i)) continue;
        for (int j = 1; j <= tot; j++) {
            if (r ^ j && b[j].test(i)) b[j] ^= b[r];
        }
        pos[r++] = i;
    }
    for (int i = r; i <= tot; i++) {
        if (b[i].test(n << 1 | 1)) printf("NO\n"), exit(0);
    }
    for (int i = 1; i < r; i++) {
        x[pos[i]] = b[i].test(n << 1 | 1);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << ".RYB"[x[i] | x[i + n] << 1];
    }
    return 0;
}
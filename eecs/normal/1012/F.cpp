#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int n, type, a[22][3], id1[22], id2[22], ans[22][2], f[1 << 22], from[1 << 22];

int main() {
    scanf("%d %d", &n, &type);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        a[i][1] += a[i][0] - 1;
    }
    vector<int> id1(n), id2(n);
    iota(id1.begin(), id1.end(), 0), iota(id2.begin(), id2.end(), 0);
    sort(id1.begin(), id1.end(), [&](int i, int j) { return a[i][0] < a[j][0]; });
    sort(id2.begin(), id2.end(), [&](int i, int j) { return a[i][2] < a[j][2]; });
    fill(f, f + (1 << n), INT_MAX), f[0] = 1;
    for (int i = 0; i < 1 << n; i++) if (f[i] < INT_MAX) {
        int p1 = 0, p2 = 0, cur = f[i];
        for (int j : id2) if (!(i >> j & 1)) {
            while (1) {
                while (p1 < n && a[id1[p1]][1] < cur) p1++;
                while (p2 < n && (!(i >> id1[p2] & 1) || a[id1[p2]][0] < cur)) p2++;
                if (p1 < n && cur >= a[id1[p1]][0]) cur = a[id1[p1]][1] + 1;
                else if (p2 < n && cur + a[j][2] >= a[id1[p2]][0]) cur = a[id1[p2]][1] + 1;
                else break;
            }
            if (cur + a[j][2] < min(a[j][0], f[i | (1 << j)])) {
                f[i | (1 << j)] = cur + a[j][2], from[i | (1 << j)] = j;
            }
        }
    }
    auto print = [&](int S, int c) {
        while (S) {
            ans[from[S]][0] = c, ans[from[S]][1] = f[S] - a[from[S]][2];
            S ^= 1 << from[S];
        }
    };
    for (int i = 0; i < 1 << n; i++) if (!i || type == 2) {
        if (f[i] == INT_MAX || f[((1 << n) - 1) ^ i] == INT_MAX) continue;
        print(((1 << n) - 1) ^ i, 1), print(i, 2);
        puts("YES");
        for (int i = 0; i < n; i++) {
            printf("%d %d\n", ans[i][0], ans[i][1]);
        }
        exit(0);
    }
    puts("NO");
    return 0;
}
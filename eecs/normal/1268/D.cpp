#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 998244353;
int n, d[maxn], _d[maxn];
char s[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
    }
    if (n <= 6) {
        int ans1 = INT_MAX, ans2;
        for (int S = 0; S < 1 << n; S++) {
            fill(d + 1, d + n + 1, 0);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if ((s[i][j] - '0') ^ (S >> (i - 1) & 1) ^ (S >> (j - 1) & 1)) d[i]++;
                }
            }
            sort(d + 1, d + n + 1);
            bool flag = 1;
            for (int i = 1, s = 0; i < n; i++) {
                s += d[i];
                if (s == i * (i - 1) / 2) { flag = 0; break; }
            }
            if (flag) {
                int c = __builtin_popcount(S);
                if (c < ans1) ans1 = c, ans2 = 1;
                else if (c == ans1) ans2++;
            }
        }
        if (ans1 == INT_MAX) puts("-1"), exit(0);
        for (int i = 1; i <= ans1; i++) ans2 = 1LL * i * ans2 % P;
        cout << ans1 << " " << ans2 << '\n', exit(0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '1') _d[i]++;
        }
    }
    int ans1 = INT_MAX, ans2;
    for (int k = 0; k <= n; k++) {
        copy(_d + 1, _d + n + 1, d + 1);
        if (k) {
            for (int i = 1; i <= n; i++) {
                if (s[k][i] == '1') d[k]--, d[i]++;
                else d[i]--, d[k]++;
            }
        }
        sort(d + 1, d + n + 1);
        bool flag = 1;
        for (int i = 1, s = 0; i < n; i++) {
            s += d[i];
            if (s == i * (i - 1) / 2) { flag = 0; break; }
        }
        if (flag) {
            int c = k > 0;
            if (c < ans1) ans1 = c, ans2 = 1;
            else if (c == ans1) ans2++;
        }
    }
    if (ans1 == INT_MAX) puts("-1"), exit(0);
    for (int i = 1; i <= ans1; i++) ans2 = 1LL * i * ans2 % P;
    cout << ans1 << " " << ans2 << '\n', exit(0);
    return 0;
}
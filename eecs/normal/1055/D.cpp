#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010, P = 998244353;
int n, pw[maxn], pre[maxn];
char s[maxn][maxn], t[maxn][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", t[i] + 1);
    }
    string S, T;
    int fir, lb, rb;
    for (int i = 1; i <= n; i++) {
        int len = strlen(s[i] + 1);
        vector<int> pos;
        for (int j = 1; j <= len; j++) {
            if (s[i][j] ^ t[i][j]) pos.push_back(j);
        }
        if (!pos.empty()) {
            fir = i, lb = pos[0], rb = pos.back(); break;
        }
    }
    int mx = INT_MIN, mn = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int len = strlen(s[i] + 1);
        vector<int> pos;
        for (int j = 1; j <= len; j++) {
            if (s[i][j] ^ t[i][j]) pos.push_back(j);
        }
        if (pos.empty()) continue;
        if (pos.back() - pos[0] != rb - lb) puts("NO"), exit(0);
        int l = pos[0], r = pos.back();
        while (l > 1 && s[i][l - 1] == s[fir][lb - 1 - (pos[0] - l)]) l--;
        while (r < len && s[i][r + 1] == s[fir][rb + 1 + (r - pos.back())]) r++;
        mx = max(mx, lb - (pos[0] - l)), mn = min(mn, rb + (r - pos.back()));
    }
    if (mx > mn) puts("NO"), exit(0);
    for (int i = mx; i <= mn; i++) {
        S.push_back(s[fir][i]), T.push_back(t[fir][i]);
    }
    int h = 0;
    for (char c : S) {
        h = (233LL * h + c) % P;
    }
    for (int i = pw[0] = 1; i <= 3000; i++) {
        pw[i] = 233LL * pw[i - 1] % P;
    }
    for (int i = 1; i <= n; i++) {
        int len = strlen(s[i] + 1);
        for (int j = 1; j <= len; j++) {
            pre[j] = (233LL * pre[j - 1] + s[i][j]) % P;
        }
        for (int j = 1; j + S.size() - 1 <= len; j++) {
            if (h == (pre[j + S.size() - 1] - 1LL * pre[j - 1] * pw[S.size()] % P + P) % P) {
                for (int k = j; k <= j + S.size() - 1; k++) s[i][k] = T[k - j];
                break;
            }
        }
        for (int j = 1; j <= len; j++) {
            if (s[i][j] != t[i][j]) puts("NO"), exit(0);
        }
    }
    puts("YES");
    printf("%s\n%s\n", S.c_str(), T.c_str());
    return 0;
}
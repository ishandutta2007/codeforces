#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 1000000007;
char s[maxn], t[maxn];
unsigned long long h[maxn], pw[maxn];

int main() {
    scanf("%s %s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[1]) cnt++;
    }
    for (int i = pw[0] = 1; i <= m; i++) {
        h[i] = (h[i - 1] * 19260817 + t[i]) % P;
        pw[i] = pw[i - 1] * 19260817 % P;
    }
    auto get = [&](int l, int r) {
        return (h[r] - h[l - 1] * pw[r - l + 1] % P + P) % P;
    };
    for (int i = 1; i * cnt <= m; i++) if (!((m - i * cnt) % (n - cnt))) {
        int len0 = i, len1 = (m - i * cnt) / (n - cnt);
        if (!len1) continue;
        unsigned long long foo = get(1, len0), bar;
        bool flag = 1, fir = 0;
        for (int j = 1, k = 1; j <= n && flag; j++) {
            if (s[j] == s[1]) {
                flag &= foo == get(k, k + len0 - 1);
                k += len0;
            } else {
                if (!fir) bar = get(k, k + len1 - 1), fir = 1;
                flag &= bar == get(k, k + len1 - 1);
                k += len1;
            }
        }
        if (flag && (len0 != len1 || foo != bar)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
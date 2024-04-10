#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;
const int MOD = 1e9 + 7;

int n, m, pr[N], y[N], len, cnt[N];
bool good[N];
char s[N];

int main() {
    scanf("%d%d %s", &n, &m, s);
    len = strlen(s);
    pr[1] = 0;
    pr[0] = -1;
    for (int i = 2; i <= len; i++) {
        int j = pr[i - 1];
        while (j >= 0 && s[j] != s[i - 1]) {
            j = pr[j];
        }
        pr[i] = j + 1;
    }
    for (int i = len; i > 0; i = pr[i]) {
        good[len - i] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &y[i]);
        cnt[y[i] - 1]++;
        cnt[y[i] + len - 1]--;
        if (i && y[i] - y[i - 1] < len && !good[y[i] - y[i - 1]]) {
            printf("0\n");
            return 0;
        }
    }
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (i) {
            cnt[i] += cnt[i - 1];
        }
        if (cnt[i] == 0) {
            ans = (ans * 26) % MOD;
        }
    }
    printf("%d\n", (int) ans);
    return 0;
}
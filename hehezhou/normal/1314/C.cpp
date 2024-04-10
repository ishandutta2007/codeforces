#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18;
struct node {
    int son[26], sze, cnt;
} t[1000010];
int n, m, tot = 1;
long long k;
inline int add(int now, char *s) {
    if (!*s) return t[now].cnt++, t[now].sze++, 1;
    if (t[now].son[*s - 'a'] == 0) t[now].son[*s - 'a'] = ++tot;
    int tmp = add(t[now].son[*s - 'a'], s + 1);
    t[now].cnt++;
    t[now].sze += ++tmp;
    return tmp;
}
inline void kth(int now, int k, char *s) {
    if (k <= t[now].cnt) return void(*s = 0);
    k -= t[now].cnt;
    for (int i = 0; i < 26; i++) {
        if (k <= t[t[now].son[i]].sze) return *s = i + 'a', kth(t[now].son[i], k, s + 1);
        else k -= t[t[now].son[i]].sze;
    }
}
char s[1010];
struct LL {
    long long x;
    inline LL& operator = (long long a) {
        return x = min(a, inf), *this;
    }
    inline LL& operator += (LL b) {
        return x = min(x + b.x, inf), *this;
    }
} dp[1010][1010];
int nxt[1010];
inline long long calc(char *chk) {
    s[n] = 'z' + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; ; j++) {
            if (s[i + j] == chk[j]) continue;
            if (s[i + j] < chk[j]) nxt[i] = n + 1;
            else nxt[i] = (chk[j] == 0 ? i + j - 1 : i + j);
            break;
        }
    }
    memset(dp, 0, sizeof dp);
    for (int i = nxt[0]; i < n; i++) dp[i][1] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            dp[nxt[j + 1]][i + 1] += dp[j][i];
        }
        for (int j = 1; j <= n; j++) dp[j][i + 1] += dp[j - 1][i + 1];
    }
    return dp[n - 1][m].x;
}
char now[1010];
int main() {
    scanf("%d%d%lld", &n, &m, &k);
    scanf("%s", s);
    for (int i = 0; i < n; i++) add(1, s + i);
    t[1].sze -= t[1].cnt;
    t[1].cnt = 0;
    int l = 1, r = n * (n + 1) / 2, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        kth(1, mid, now);
        if (calc(now) >= k) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    kth(1, ans, now);
    return puts(now), 0;
}
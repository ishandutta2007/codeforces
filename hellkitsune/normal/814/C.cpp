#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
char s[1555];
int a[1555];
int cnt[26], mx[26];
int need[26][1555];

int main() {
    scanf("%d%s", &n, s);
    forn(i, n) a[i] = int(s[i] - 'a');
    forn(i, 26) forn(j, 1555) {
        need[i][j] = INF;
    }
    forn(i, 26) need[i][0] = 0;
    for (int len = 1; len <= n; ++len) {
        memset(cnt, 0, sizeof cnt);
        memset(mx, 0, sizeof mx);
        forn(i, len) {
            ++cnt[a[i]];
            ++mx[a[i]];
        }
        for (int i = len; i < n; ++i) {
            --cnt[a[i - len]];
            ++cnt[a[i]];
            mx[a[i]] = max(mx[a[i]], cnt[a[i]]);
        }
        forn(i, 26) need[i][len] = len - mx[i];
    }
    int q;
    scanf("%d", &q);
    forn(i, q) {
        int can, x;
        char c;
        scanf("%d %c", &can, &c);
        x = int(c - 'a');
        int len = lower_bound(need[x] + 1, need[x] + n + 5, can + 1) - need[x];
        printf("%d\n", len - 1);
    }
    return 0;
}
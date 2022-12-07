#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005;

int n, s;
int a[N];
int cnt[N];

int main() {
    scanf("%d%d", &n, &s);
    --s;
    forn(i, n) {
        scanf("%d", a + i);
    }
    if (n == 1) {
        int ans = 0;
        if (a[0] != 0) {
            ans = 1;
        }
        printf("%d\n", ans);
        return 0;
    }
    memset(cnt, 0, sizeof cnt);
    int fu = 0;
    if (a[s] != 0) {
        ++fu;
    }
    forn(i, n) {
        if (i == s) {
            continue;
        }
        ++cnt[a[i]];
    }
    int z = 0;
    int ext = cnt[0];
    for (int i = 1; i < n; ++i) {
        z += (cnt[i] == 0);
    }
    int ans = max(z, ext);
    for (int i = n - 2; i > 0; --i) {
        z -= (cnt[i + 1] == 0);
        ext += cnt[i + 1];
        ans = min(ans, max(z, ext));
    }
    printf("%d\n", ans + fu);
    return 0;
}
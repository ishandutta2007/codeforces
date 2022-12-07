#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[200005];
char t[200005];

int c[400005], sa[200005], lcp[200005];
LL ord[200005];
const int MASK = (1 << 21) - 1;

void saLcp(char *s, int n) {
    forn(i, n) c[i] = s[i];
    for (int sz = 1; sz < max(2, n); sz <<= 1) {
        forn(i, n) ord[i] = ((((LL)c[i] << 21) | c[i + sz]) << 21) | i;
        sort(ord, ord + n);
        int cnt = 0;
        forn(i, n) {
            c[ord[i] & MASK] = cnt + 1;
            if ((ord[i] >> 21) != (ord[i + 1] >> 21)) ++cnt;
        }
        if (cnt == n) break;
    }
    forn(i, n) sa[c[i]] = i;
    sa[0] = n;
    for (int i = 0, j, k = 0; i < n; lcp[c[i++]] = k) {
        if (c[i] > 0) for (k ? k-- : 0, j = sa[c[i] - 1]; s[i + k] == s[j + k]; k++);
        else k = 0;
    }
    forn(i, n) sa[i] = sa[i + 1], lcp[i] = lcp[i + 1];
}

int a[200000], can[200001];
int lo[200000], hi[200000];
LL ans = 0;

void solve() {
    forn(i, n) can[i + 1] += can[i];
    for (int i = 1; i < n; ++i) {
        lo[i] = i;
        while (lo[i] > 1 && a[lo[i] - 1] >= a[i]) lo[i] = lo[lo[i] - 1];
    }
    for (int i = n - 1; i >= 1; --i) {
        hi[i] = i;
        while (hi[i] < n - 1 && a[hi[i] + 1] >= a[i]) hi[i] = hi[hi[i] + 1];
    }
    for (int i = 1; i < n; ++i) {
        ans = max(ans, (LL)a[i] * (can[hi[i] + 1] - can[lo[i] - 1]));
    }
    cout << ans << endl;
}

int main() {
    scanf("%d%s%s", &n, s, t);
    reverse(s, s + n);
    reverse(t, t + n);
    forn(i, n) if (t[i] == '0') {
        ans = max(ans, (LL)n - i);
    }
    saLcp(s, n);
    forn(i, n) a[i] = lcp[i];
    forn(i, n) can[i + 1] = t[sa[i]] == '0';
    solve();
    return 0;
}
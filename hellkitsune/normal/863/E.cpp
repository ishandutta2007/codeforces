#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int from[200000], to[200000];
int all[400000], allc;

int a[400005];

int st[1 << 20];
const int OFF = 1 << 19;

void stBuild() {
    forn(i, allc) st[OFF + i] = a[i];
    for (int i = OFF - 1; i >= 1; --i) {
        st[i] = min(st[2 * i], st[2 * i + 1]);
    }
}

int stGet(int v, int L, int R, int l, int r) {
    if (l > r) return 12341234;
    if (l == L && r == R) {
        return st[v];
    }
    int mid = (L + R) >> 1;
    return min(stGet(2 * v, L, mid, l, min(r, mid)),
        stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r));
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", from + i, to + i), ++to[i];
    forn(i, n) {
        all[i] = from[i];
        all[n + i] = to[i];
    }
    allc = 2 * n;
    sort(all, all + allc);
    allc = unique(all, all + allc) - all;
    forn(i, n) {
        from[i] = lower_bound(all, all + allc, from[i]) - all;
        to[i] = lower_bound(all, all + allc, to[i]) - all;
    }
    forn(i, n) {
        ++a[from[i]];
        --a[to[i]];
    }
    for (int i = 1; i < allc; ++i) {
        a[i] += a[i - 1];
    }
    stBuild();
    forn(i, n) {
        int res = stGet(1, 0, OFF - 1, from[i], to[i] - 1);
        assert(res > 0);
        if (res > 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[200005];
vector<int> lens;
vector<int> edges;

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) {
        scanf("%d", a + i);
    }
    bool ok = true;
    forn(i, n) if (a[i] < 0) {
        ok = false;
        break;
    }
    if (ok) {
        cout << 0 << endl;
        return 0;
    }
    int cur = 1;
    int ans = 0;
    forn(i, n) {
        if (a[i] < 0) {
            if (cur == 1) {
                cur = -1;
                ++ans;
            }
            --k;
        } else {
            if (cur == -1) {
                cur = 1;
                ++ans;
            }
        }
    }
    if (k < 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int beg = 0; beg < n; ) {
        if (a[beg] < 0) {
            ++beg;
            continue;
        }
        int end = beg + 1;
        while (end < n && a[end] >= 0) {
            ++end;
        }
        if (beg == 0 || end == n) {
            if (end == n) {
                edges.pb(end - beg);
            }
        } else {
            lens.pb(end - beg);
        }
        beg = end;
    }
    sort(lens.begin(), lens.end());
    int tot = ans;
    forn(mask, 1 << int(edges.size())) {
        int rem = k;
        int cur = tot;
        forn(i, edges.size()) if (mask & (1 << i)) {
            rem -= edges[i];
            --cur;
        }
        if (rem < 0) {
            continue;
        }
        for (int x : lens) {
            if (rem >= x) {
                rem -= x;
                cur -= 2;
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
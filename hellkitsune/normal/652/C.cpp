#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int p[300000], rev[300000];
int a[300000], b[300000];
vector<int> va[300000], vb[300000];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", p + i), --p[i];
    REP(i, n) rev[p[i]] = i;
    REP(i, m) {
        scanf("%d%d", a + i, b + i), --a[i], --b[i];
        a[i] = rev[a[i]];
        b[i] = rev[b[i]];
        if (a[i] > b[i]) swap(a[i], b[i]);
        va[a[i]].pb(i);
        vb[b[i]].pb(i);
    }
    LL ans = 0;
    int j = 0, bad = 0;
    REP(i, n) {
        while (j < n && bad == 0) {
            for (int x : vb[j]) if (a[x] >= i) {
                ++bad;
            }
            ++j;
        }
        int k = j - 1;
        if (bad == 0) ++k;
        ans += k - i;
        for (int x : va[i]) if (b[x] < j) {
            --bad;
        }
    }
    cout << ans << endl;
    return 0;
}
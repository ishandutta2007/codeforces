#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(2e9) + 123;

int n, x;
int l[200000], r[200000], cost[200000];
vector<PII> ll[200001], rr[200001];

int main() {
    scanf("%d%d", &n, &x);
    forn(i, n) {
        int l, r, cost;
        scanf("%d%d%d", &l, &r, &cost);
        ::l[i] = l, ::r[i] = r, ::cost[i] = cost;
        int len = r - l + 1;
        ll[len].pb(mp(l, cost));
        rr[len].pb(mp(r, cost));
    }
    forn(i, x + 1) {
        sort(ll[i].begin(), ll[i].end());
        sort(rr[i].begin(), rr[i].end());
        for (int j = (int)ll[i].size() - 2; j >= 0; --j) {
            ll[i][j].second = min(ll[i][j].second, ll[i][j + 1].second);
        }
        forn(j, (int)rr[i].size() - 1) {
            rr[i][j + 1].second = min(rr[i][j + 1].second, rr[i][j].second);
        }
    }
    int ans = INF;
    forn(i, n) {
        int len = x - (r[i] - l[i] + 1);
        if (len <= 0) {
            continue;
        }
        auto it = lower_bound(ll[len].begin(), ll[len].end(), mp(r[i] + 1, -1));
        if (it != ll[len].end()) {
            ans = min(ans, cost[i] + it->second);
        }
        it = lower_bound(rr[len].begin(), rr[len].end(), mp(l[i], -1));
        if (it != rr[len].begin()) {
            --it;
            ans = min(ans, cost[i] + it->second);
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
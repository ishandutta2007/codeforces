#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9) + 123;
const LL INF64 = LL(1e18) + 123;

int n, m, k;
vector<PII> a[1000001], b[1000001];
LL c[1000001], d[1000001];
int cost[100000], need;
LL tot;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, m) {
        int day, from, to, w;
        scanf("%d%d%d%d", &day, &from, &to, &w);
        if (to == 0) {
            a[day].pb(mp(from - 1, w));
        } else {
            assert(from == 0);
            b[day].pb(mp(to - 1, w));
        }
    }
    forn(i, n) cost[i] = INF;
    need = n;
    tot = 0;
    for (int i = 1; i <= 1000000; ++i) {
        for (PII p : a[i]) {
            if (cost[p.first] == INF) {
                --need;
                cost[p.first] = p.second;
                tot += p.second;
            } else if (cost[p.first] > p.second) {
                tot += p.second - cost[p.first];
                cost[p.first] = p.second;
            }
        }
        if (need > 0) {
            c[i] = INF64;
        } else {
            c[i] = tot;
        }
    }
    forn(i, n) cost[i] = INF;
    need = n;
    tot = 0;
    for (int i = 1000000; i >= 1; --i) {
        for (PII p : b[i]) {
            if (cost[p.first] == INF) {
                --need;
                cost[p.first] = p.second;
                tot += p.second;
            } else if (cost[p.first] > p.second) {
                tot += p.second - cost[p.first];
                cost[p.first] = p.second;
            }
        }
        if (need > 0) {
            d[i] = INF64;
        } else {
            d[i] = tot;
        }
    }
    LL ans = INF64;
    for (int i = 1; i <= 1000000; ++i) {
        int j = i + k + 1;
        if (j <= 1000000) {
            ans = min(ans, c[i] + d[j]);
        }
    }
    if (ans == INF64) ans = -1;
    cout << ans << endl;
    return 0;
}
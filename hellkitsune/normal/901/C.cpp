#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
vector<int> g[300005];
int used[300005];
int st[300005], stsz = 0;
int a[300005];
LL p[300005];

void dfs(int v, int par) {
    used[v] = 1;
    st[stsz++] = v;

    for (int to : g[v]) if (to != par) {
        if (used[to] == 0) {
            dfs(to, v);
        } else if (used[to] == 1) {
            int mn, mx;
            mn = mx = to;
//            cerr << to << ' ';
            for (int i = stsz - 1; st[i] != to; --i) {
//                cerr << st[i] << ' ';
                mn = min(mn, st[i]);
                mx = max(mx, st[i]);
            }
//            cerr << endl;
            a[mn] = mx - 1;
        }
    }

    used[v] = 2;
    --stsz;
}

LL sum2(LL x) {
    if (x < 0) return 0;
    return x * (x + 1) / 2;
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) a[i] = n - 1;
    forn(i, n) if (!used[i]) {
        dfs(i, -1);
    }
    for (int i = n - 2; i >= 0; --i) {
        a[i] = min(a[i], a[i + 1]);
    }
    p[0] = 0;
    forn(i, n) p[i + 1] = p[i] + a[i];
    scanf("%d", &q);
    forn(_, q) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        LL ans = p[to + 1] - p[from] - sum2(to) + sum2(from - 1) + to - from + 1;
        int ind = lower_bound(a + from, a + to + 1, to + 1) - a;
//        if (ind != to + 1) cerr << "!" << endl;
        ans -= p[to + 1] - p[ind];
        ans += (LL)(to + 1 - ind) * to;
        printf("%I64d\n", ans);
    }
    return 0;
}
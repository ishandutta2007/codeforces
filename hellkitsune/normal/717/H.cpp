#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[50005];
vector<int> t[50005];
int T;
int col[1000005];
int team[50005];
mt19937 mt(1235577);
int x[100005], y[100005];
int ans[50005];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        x[i] = from;
        y[i] = to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) {
        int cnt;
        scanf("%d", &cnt);
        forn(j, cnt) {
            int x;
            scanf("%d", &x), --x;
            T = max(T, x + 1);
            t[i].pb(x);
        }
    }
    int times = 0;
    while (true) {
        assert(times++ < 100);
        forn(i, T) {
            col[i] = mt() & 1;
        }
        bool ok = true;
        bool was[2];
        forn(i, n) {
            was[0] = was[1] = false;
            for (int x : t[i]) {
                was[col[x]] = true;
            }
            if (!was[0] || !was[1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    while (true) {
        forn(i, n) team[i] = mt() & 1;
        int cnt = 0;
        forn(i, m) if (team[x[i]] != team[y[i]]) {
            ++cnt;
        }
        if (2 * cnt < m) {
            continue;
        }
        forn(i, n) {
            for (int x : t[i]) if (col[x] == team[i]) {
                ans[i] = x;
                break;
            }
        }
//        forn(i, n) cerr << team[i] + 1 << ' ';
//        cerr << endl;
        bool firstTime = true;
        forn(i, n) {
            if (!firstTime) {
                printf(" ");
            }
            firstTime = false;
            printf("%d", ans[i] + 1);
        }
        printf("\n");

        firstTime = true;
        forn(i, T) {
            if (!firstTime) {
                printf(" ");
            }
            firstTime = false;
            printf("%d", col[i] + 1);
        }
        printf("\n");
        break;
    }
    return 0;
}
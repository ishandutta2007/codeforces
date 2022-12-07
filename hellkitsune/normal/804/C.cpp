#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL test;

int n, m;
vector<int> g[300005];
vector<int> s[300005];

mt19937 mt(123);

inline int myRand(int bound) {
    return mt() % bound;
}

void genCol(int v, int par, int col) {
    s[v].pb(col);
    for (int to : g[v]) if (to != par && (mt() & 1)) {
        genCol(to, v, col);
    }
}

void genTest() {
    n = mt() % 7 + 1;
    m = mt() % 7 + 1;
    int ord[n];
    forn(i, n) ord[i] = i;
    random_shuffle(ord, ord + n, myRand);
    forn(i, n) {
        g[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int to = mt() % i;
        g[ord[i]].pb(ord[to]);
        g[ord[to]].pb(ord[i]);
    }
    forn(i, n) s[i].clear();
    forn(i, m) {
        int st = mt() % n;
        genCol(st, -1, i);
    }
}

void readTest() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        int cnt;
        scanf("%d", &cnt);
        s[i].clear();
        forn(j, cnt) {
            int x;
            scanf("%d", &x), --x;
            s[i].pb(x);
        }
    }
    forn(i, n) g[i].clear();
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
}

int cnt;
int ans[300005];
bool used[300005];

set<int> can;

void dfs(int v, int par) {
    for (int col : s[v]) if (ans[col] != -1) {
        can.erase(ans[col]);
    }
    for (int col : s[v]) if (ans[col] == -1) {
        ans[col] = *can.begin();
        can.erase(can.begin());
    }
    for (int col : s[v]) {
        can.insert(ans[col]);
    }
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
    }
}

void solve() {
    cnt = 1;
    forn(i, n) cnt = max(cnt, (int)s[i].size());
    forn(i, m) {
        ans[i] = -1;
    }
    forn(i, cnt) can.insert(i);
    dfs(0, -1);
    forn(i, m) if (ans[i] == -1) {
        ans[i] = cnt - 1;
    }
}

bool check() {
    forn(i, m) if (ans[i] < 0 || ans[i] >= cnt) {
        return false;
    }
    forn(i, n) {
        for (int x : s[i]) for (int y : s[i]) {
            if (y == x) break;
            if (ans[x] == ans[y]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    readTest();
    solve();
    printf("%d\n", cnt);
    forn(i, m) {
        printf("%d ", ans[i] + 1);
    }
    puts("");
}

//int main() {
//    for (test = 0; test < 123412341234ll; ++test) {
//        genTest();
//        solve();
//        if (!check()) {
//            cout << "WA " << test << endl;
//            printf("%d %d\n", n, m);
//            forn(i, n) for (int to : g[i]) if (to > i) {
//                printf("%d %d\n", i, to);
//            }
//            puts("");
//            forn(i, n) {
//                printf("%d:", i);
//                for (int x : s[i]) {
//                    printf(" %d", x);
//                }
//                puts("");
//            }
//            puts("");
//            forn(i, m) printf("%d ", ans[i]);
//            puts("");
//            return 0;
//        }
//        if (!(test & 32767)) {
//            cout << "OK " << test << endl;
//        }
//    }
//    return 0;
//}
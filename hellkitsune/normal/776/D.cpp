#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int r[100000];
vector<int> v[100000];
vector<PII> g[100000];
int col[100000];

void dfs(int v, int c) {
    if (col[v] == -1) {
        col[v] = c;
    } else {
        if (col[v] != c) {
            cout << "NO" << endl;
            exit(0);
        }
        return;
    }
    for (PII to : g[v]) {
        dfs(to.first, c ^ to.second);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%d", r + i);
    forn(i, m) {
        int cnt;
        scanf("%d", &cnt);
        forn(_, cnt) {
            int x;
            scanf("%d", &x), --x;
            v[x].pb(i);
        }
    }
    forn(i, n) {
        g[v[i][0]].pb(mp(v[i][1], r[i] ^ 1));
        g[v[i][1]].pb(mp(v[i][0], r[i] ^ 1));
    }
    forn(i, m) col[i] = -1;
    forn(i, m) if (col[i] == -1) {
        dfs(i, 0);
    }
    cout << "YES" << endl;
    return 0;
}
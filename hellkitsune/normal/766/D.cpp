#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
int c[100000];
vector<int> cv[100000];
int col[100000];
string dic[100000];

bool addEdge(int u, int v, int x) {
    if (c[u] == c[v]) {
        return (col[u] ^ col[v]) == x;
    }
    x ^= col[u] ^ col[v];
    u = c[u];
    v = c[v];
    if (cv[u].size() < cv[v].size()) {
        swap(u, v);
    }
    for (int y : cv[v]) {
        cv[u].pb(y);
        col[y] ^= x;
        c[y] = u;
    }
    cv[v].clear();
    return true;
}

char buf[333];

int getInt(string s) {
    return int(lower_bound(dic, dic + n, s) - dic);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    forn(i, n) {
        scanf("%s", buf);
        dic[i] = string(buf);
    }
    sort(dic, dic + n);
    forn(i, n) {
        col[i] = 0;
        c[i] = i;
        cv[i].pb(i);
    }
    forn(i, m) {
        int from, to, x;
        scanf("%d", &x), --x;
        scanf("%s", buf), from = getInt(string(buf));
        scanf("%s", buf), to = getInt(string(buf));
        if (addEdge(from, to, x)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    forn(i, q) {
        int from, to;
        scanf("%s", buf), from = getInt(string(buf));
        scanf("%s", buf), to = getInt(string(buf));
        if (c[from] != c[to]) {
            printf("3\n");
        } else if (col[from] == col[to]) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
    return 0;
}
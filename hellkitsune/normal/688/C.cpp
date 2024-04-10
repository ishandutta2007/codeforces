#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[100000];
bool ok = true;
int col[100000];

void go(int v) {
    for (int to : g[v]) if (col[to] == -1) {
        col[to] = col[v] ^ 1;
        go(to);
    } else if (col[to] == col[v]) {
        ok = false;
    }
}

vector<int> a, b;

void out(vector<int> &a) {
    printf("%d\n", (int)a.size());
    for (int x : a) printf("%d ", x);
    printf("\n");
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    REP(i, n) col[i] = -1;
    REP(i, n) if (col[i] == -1) {
        col[i] = 0;
        go(i);
    }
    if (!ok) {
        printf("-1\n");
        return 0;
    }
    REP(i, n) if (col[i] == 0) {
        a.pb(i + 1);
    } else {
        b.pb(i + 1);
    }
    out(a);
    out(b);
    return 0;
}
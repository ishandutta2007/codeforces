#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    map<int, int> cnt;
    int mx;
    LL ans;
};

int n;
int c[100000];
LL ans[100000];
vector<int> g[100000];
S *s[100000];

void mergeStructs(S &a, S &b) {
    for (PII x : b.cnt) {
        int cur = (a.cnt[x.first] += x.second);
        if (cur > a.mx) {
            a.mx = cur;
            a.ans = x.first;
        } else if (cur == a.mx) {
            a.ans += x.first;
        }
    }
}

void dfs(int v, int p) {
    s[v] = new S();
    s[v]->cnt[c[v]] = 1;
    s[v]->mx = 1;
    s[v]->ans = c[v];
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
        if (s[v]->cnt.size() < s[to]->cnt.size()) swap(s[v], s[to]);
        mergeStructs(*s[v], *s[to]);
    }
    ans[v] = s[v]->ans;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", c + i);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    REP(i, n) printf("%I64d ", ans[i]);
    printf("\n");
    return 0;
}
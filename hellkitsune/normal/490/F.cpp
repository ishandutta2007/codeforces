#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[6000], all[6000];
vector<int> g[6000];

int curState = 0;
int *ptrs[5000000];
int vals[5000000];

void change(int &ptr, int val) {
    ptrs[curState] = &ptr;
    vals[curState] = ptr;
    ++curState;
    ptr = val;
}

void rollback(int savedState) {
    while (curState > savedState) {
        --curState;
        *ptrs[curState] = vals[curState];
    }
}

int fen[6000];
int ans = 0;

void fenUpdate(int ind, int val) {
    for (; ind < n; ind |= ind + 1) {
        if (fen[ind] < val) {
            change(fen[ind], val);
        }
    }
}

int fenGet(int ind) {
    int res = 0;
    for (; ind >= 0; ind = (ind & (ind + 1)) - 1) {
        res = max(res, fen[ind]);
    }
    return res;
}

void dfs(int v, int par) {
    int savedState = curState;

    int here = fenGet(a[v] - 1) + 1;
    fenUpdate(a[v], here);
    ans = max(ans, here);
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
    }

    rollback(savedState);
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) all[i] = a[i];
    sort(all, all + n);
    int cnt = unique(all, all + n) - all;
    forn(i, n) a[i] = lower_bound(all, all + cnt, a[i]) - all;
    forn(i, n) {
        dfs(i, -1);
        assert(curState == 0);
    }
    cout << ans << endl;
    return 0;
}
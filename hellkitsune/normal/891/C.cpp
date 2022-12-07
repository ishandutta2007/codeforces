#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 500005;

int n, m, q;
int from[N], to[N], w[N];
vector<int> v[N];
vector<int> where[N], e[N];
int ind[N];

inline bool cmp(const int &lhs, const int &rhs) {
    return w[lhs] < w[rhs];
}

int curState = 0, savedState = 0;
int *ptrs[4 * N];
int vals[4 * N];

void change(int &ptr, int val) {
    ptrs[curState] = &ptr;
    vals[curState] = ptr;
    ++curState;
    ptr = val;
}

void saveState() {
    savedState = curState;
}

void rollback() {
    while (curState > savedState) {
        --curState;
        *ptrs[curState] = vals[curState];
    }
}


int par[N], ra[N];

void dsuInit() {
    forn(i, n) par[i] = i, ra[i] = 1;
}

inline int dsuParent(int v) {
    while (v != par[v]) {
        v = par[v];
    }
    return v;
}

bool dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return false;
    if (ra[u] < ra[v]) swap(u, v);
    change(par[v], u);
    change(ra[u], ra[u] + ra[v]);
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        scanf("%d%d%d", from + i, to + i, w + i);
        --from[i], --to[i];
    }
    scanf("%d", &q);
    forn(i, q) {
        int cnt;
        scanf("%d", &cnt);
        v[i].reserve(cnt);
        v[i].resize(cnt);
        forn(j, cnt) {
            scanf("%d", &v[i][j]);
            --v[i][j];
        }
    }
    dsuInit();
    forn(i, q) {
        sort(v[i].begin(), v[i].end(), cmp);
        for (int x : v[i]) {
            if (where[w[x]].empty() || where[w[x]].back() != i) {
                where[w[x]].pb(i);
            }
        }
    }
    forn(i, m) e[w[i]].pb(i);
    for (int i = 1; i < N; ++i) {
        for (int x : where[i]) {
            if (ind[x] == -1) {
                continue;
            }
            saveState();
            while (ind[x] != (int)v[x].size() && w[v[x][ind[x]]] == i) {
                int eind = v[x][ind[x]];
                if (!dsuMerge(from[eind], to[eind])) {
                    ind[x] = -1;
                    break;
                }
                ++ind[x];
            }
            rollback();
        }
        for (int x : e[i]) {
            dsuMerge(from[x], to[x]);
        }
    }
    forn(i, q) if (ind[i] == -1) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
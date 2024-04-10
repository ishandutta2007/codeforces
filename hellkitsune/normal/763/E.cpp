#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int SZ = (1 << 18) + 1;
const int off = 1 << 17;
int TMP = 1 << 18;

int n, k;
int st[SZ][10];
int cnt[SZ], from[SZ], to[SZ], dif[SZ], res[SZ];
vector<int> g[100000];
bool have[20];
int num[20];
int tmp[10];

void stMerge(int u, int v, int z) {
    from[z] = from[u];
    to[z] = to[v];
    if (cnt[u] == 0) {
        forn(i, 10) {
            st[z][i] = st[v][i];
        }
        from[z] = from[v];
        to[z] = to[v];
        cnt[z] = cnt[v];
        dif[z] = dif[v];
        res[z] = res[v];
        return;
    } else if (cnt[v] == 0) {
        forn(i, 10) {
            st[z][i] = st[u][i];
        }
        from[z] = from[u];
        to[z] = to[u];
        cnt[z] = cnt[u];
        dif[z] = dif[u];
        res[z] = res[u];
        return;
    }
    int &c = cnt[z] = 0;
    int (&res)[10] = st[z];
    int (&rr) = ::res[z] = ::res[u] + ::res[v];
    int mu = min(5, cnt[u]);
    int mv = min(5, cnt[v]);

    for (int i = cnt[u] - mu; i < cnt[u]; ++i) {
        tmp[c++] = st[u][i];
    }
    forn(i, mv) {
        tmp[c++] = st[v][i] + dif[u];
    }
    int cc = 0;
    if (cnt[u] + cnt[v] <= 10) {
        forn(i, cnt[u]) {
            res[cc++] = st[u][i];
        }
        forn(i, cnt[v]) {
            res[cc++] = st[v][i] + dif[u];
        }
    } else {
        forn(i, mu) {
            res[cc++] = st[u][i];
        }
        forn(i, 5 - mu) {
            res[cc++] = st[v][i] + dif[u];
        }
        for (int i = cnt[u] - (5 - mv); i < cnt[u]; ++i) {
            res[cc++] = st[u][i];
        }
        for (int i = cnt[v] - mv; i < cnt[v]; ++i) {
            res[cc++] = st[v][i] + dif[u];
        }
    }
    forn(i, mu) {
        for (int x : g[to[u] - mu + i + 1]) {
            if (x < from[v] || x > to[v]) {
                continue;
            }
            int ind = x - from[v] + mu;
            if (tmp[i] != tmp[ind]) {
                --rr;
                int was = max(tmp[i], tmp[ind]);
                int cur = min(tmp[i], tmp[ind]);
                forn(j, c) {
                    if (tmp[j] == was) {
                        tmp[j] = cur;
                    }
                }
                forn(j, cc) {
                    if (res[j] == was) {
                        res[j] = cur;
                    }
                }
            }
        }
    }
    c = cc;
    forn(i, 20) {
        have[i] = false;
    }
    forn(i, c) {
        have[res[i]] = true;
    }
    int cur = 0;
    forn(i, 20) if (have[i]) {
        num[i] = cur++;
    }
    forn(i, c) {
        res[i] = num[res[i]];
    }
    dif[z] = cur;
}

void stBuild() {
    for (int v = off; v < 2 * off; ++v) {
        int ind = v - off;
        if (ind < n) {
            st[v][0] = 0;
            cnt[v] = 1;
            from[v] = ind;
            to[v] = ind;
            dif[v] = 1;
            res[v] = 1;
        } else {
            cnt[v] = 0;
            from[v] = ind;
            to[v] = ind - 1;
            dif[v] = 0;
            res[v] = 0;
        }
    }
    for (int i = off - 1; i > 0; --i) {
        stMerge(2 * i, 2 * i + 1, i);
    }
}

void stGet(int v, int L, int R, int l, int r) {
    if (l > r) {
        return;
    }
    if (L == l && R == r) {
        forn(i, cnt[0]) {
            st[TMP][i] = st[0][i];
        }
        cnt[TMP] = cnt[0];
        from[TMP] = from[0];
        to[TMP] = to[0];
        dif[TMP] = dif[0];
        res[TMP] = res[0];
        stMerge(TMP, v, 0);
        return;
    }
    int mid = (L + R) >> 1;
    stGet(2 * v, L, mid, l, min(r, mid));
    stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

int m, q;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &k, &m);
    forn(i, m) {
        int from, to;;
        scanf("%d%d", &from, &to), --from, --to;
        if (from > to) {
            swap(from, to);
        }
        g[from].pb(to);
    }

    stBuild();
    scanf("%d", &q);
    forn(_, q) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;

        cnt[0] = 0;
        ::from[0] = 0;
        ::to[0] = -1;
        dif[0] = 0;
        res[0] = 0;

        stGet(1, 0, off - 1, from, to);
        printf("%d\n", res[0]);
    }
    return 0;
}
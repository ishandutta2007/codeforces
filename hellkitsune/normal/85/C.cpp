#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int le[100000], ri[100000], par[100000], key[100000], mx[100001];
int wl[100000], wr[100000];
int cnt[100000] = {};
LL tot[100000] = {};
vector<int> leaves;

void dfs(int v) {
    if (le[v] >= 0) dfs(le[v]);
    if (ri[v] >= 0) dfs(ri[v]);
    wl[v] = (le[v] >= 0) ? wl[le[v]] : key[v];
    wr[v] = (ri[v] >= 0) ? wr[ri[v]] : key[v];
}

void dfs2(int v) {
    if (le[v] >= 0) {
        cnt[le[v]] = cnt[v];
        tot[le[v]] = tot[v];
        mx[le[v]] = min(mx[v], key[v] - 1);
        if (ri[v] >= 0) {
            ++cnt[le[v]];
            tot[le[v]] += wl[ri[v]];
        }
        dfs2(le[v]);
    }
    if (ri[v] >= 0) {
        cnt[ri[v]] = cnt[v];
        tot[ri[v]] = tot[v];
        mx[ri[v]] = mx[v];
        if (le[v] >= 0) {
            ++cnt[ri[v]];
            tot[ri[v]] += wr[le[v]];
        }
        dfs2(ri[v]);
    }
    if (le[v] < 0 && ri[v] < 0) leaves.pb(v);
}

inline bool cmp(const int &lhs, const int &rhs) {
    return mx[lhs] < mx[rhs];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) le[i] = ri[i] = par[i] = -1;
    REP(i, n) {
        int p, k;
        scanf("%d%d", &p, &k);
        if (p > 0) --p;
        par[i] = p;
        key[i] = k;
    }
    REP(i, n) {
        int p = par[i];
        int k = key[i];
        if (p >= 0) {
            if (k < key[p]) le[p] = i;
            else ri[p] = i;
        }
    }
    int root = 0;
    while (par[root] >= 0) ++root;
    REP(i, n) mx[i] = 1e9 + 100;
    dfs(root);
    dfs2(root);
    sort(leaves.begin(), leaves.end(), cmp);
    int q;
    scanf("%d", &q);
    REP(query, q) {
        int k;
        scanf("%d", &k);
        mx[100000] = k;
        int pos = lower_bound(leaves.begin(), leaves.end(), 100000, cmp) - leaves.begin();
        printf("%.12f\n", (double)tot[leaves[pos]] / cnt[leaves[pos]]);
    }
    return 0;
}
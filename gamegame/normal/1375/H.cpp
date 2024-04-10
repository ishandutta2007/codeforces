#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int BLOCK = 256;
const int maxN = (1 << 12) + 10;
int a[maxN];
int CUR;
vector < pair < int, int > > add;
int get(int x, int y) {
    add.emplace_back(x, y);
    return ++CUR;
}
vector < vector < int > > build_full(vector < int >& inds, int l, int r) {
    int N = inds.size();
    assert(N != 0);
    assert(inds.size() == r - l + 1);
    if (inds.size() == 1) {
        vector < vector < int > > d(N, vector < int >(N, -1));
        d[0][0] = inds[0];
        return d;
    }
    int mid = (l + r) / 2;
    vector < int > f1, f2;
    for (int& p : inds) {
        if (a[p] <= mid) {
            f1.emplace_back(p);
        }
        else {
            f2.emplace_back(p);
        }
    }
    auto d1 = build_full(f1, l, mid);
    auto d2 = build_full(f2, mid + 1, r);
    vector < vector < int > > d(N, vector < int >(N, -1));
    for (int x = 0; x < inds.size(); x++) {
        int pl_1 = 0;
        while (pl_1 < f1.size() && f1[pl_1] < inds[x]) pl_1++;
        int pr_1 = pl_1 - 1;
        int pl_2 = 0;
        while (pl_2 < f2.size() && f2[pl_2] < inds[x]) pl_2++;
        int pr_2 = pl_2 - 1;
        for (int y = x; y < inds.size(); y++) {
            while (pr_1 + 1 < f1.size() && f1[pr_1 + 1] <= inds[y]) pr_1++;
            while (pr_2 + 1 < f2.size() && f2[pr_2 + 1] <= inds[y]) pr_2++;
            if (pl_1 > pr_1) {
                assert(pl_2 <= pr_2);
                d[x][y] = d2[pl_2][pr_2];
            }
            else if (pl_2 > pr_2) {
                assert(pl_1 <= pr_1);
                d[x][y] = d1[pl_1][pr_1];
            }
            else {
                d[x][y] = get(d1[pl_1][pr_1], d2[pl_2][pr_2]);
            }
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    CUR = n;
    vector < vector < vector < int > > > vals;
    vector < vector < int > > inds;
    for (int l = 1; l <= n; l += BLOCK) {
        int r = min(l + BLOCK - 1, n);
        vector < int > gg;
        for (int p = 1; p <= n; p++) {
            if (a[p] >= l && a[p] <= r) gg.emplace_back(p);
        }
        inds.emplace_back(gg);
        assert(gg.size() == r - l + 1);
        vals.emplace_back(build_full(gg, l, r));
    }
    vector < int > ans;
    for (int i = 0; i < q; i++) {
        int from, to;
        cin >> from >> to;
        int T = -1;
        for (int z = 0; z < inds.size(); z++) {
            int from1 = lower_bound(inds[z].begin(), inds[z].end(), from) - inds[z].begin();
            int to1 = upper_bound(inds[z].begin(), inds[z].end(), to) - inds[z].begin() - 1;
            if (from1 > to1) continue;
            if (T == -1) {
                T = vals[z][from1][to1];
            }
            else {
                T = get(T, vals[z][from1][to1]);
            }
        }
        assert(T != -1);
        ans.emplace_back(T);
    }
    cout << CUR << '\n';
    for (auto& it : add) {
        cout << it.first << " " << it.second << '\n';
    }
    for (int v : ans) cout << v << " ";

    return 0;
}
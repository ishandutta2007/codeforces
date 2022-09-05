#include <bits/stdc++.h>
using namespace std;

// https://atcoder.github.io/ac-library/production/document_en/string.html
namespace atcoder {
namespace internal {
vector<int> sa_naive(const vector<int>& s) {
    int n = int(s.size());
    vector<int> sa(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

vector<int> sa_doubling(const vector<int>& s) {
    int n = int(s.size());
    vector<int> sa(n), rnk = s, tmp(n);
    iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        swap(tmp, rnk);
    }
    return sa;
}

// SA-IS, linear-time suffix array construction
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
vector<int> sa_is(const vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < THRESHOLD_NAIVE) {
        return sa_naive(s);
    }
    if (n < THRESHOLD_DOUBLING) {
        return sa_doubling(s);
    }

    vector<int> sa(n);
    vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const vector<int>& lms) {
        fill(sa.begin(), sa.end(), -1);
        vector<int> buf(upper + 1);
        copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
        }
    }
    vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa) {
            if (lms_map[v] != -1) sorted_lms.push_back(v);
        }
        vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
        }
        induce(sorted_lms);
    }
    return sa;
}
} // namespace internal

vector<int> suffix_array(const vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> vector<int> suffix_array(const vector<T>& s) {
    int n = int(s.size());
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

vector<int> suffix_array(const string& s) {
    int n = int(s.size());
    vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}

template <class T>
vector<int> lcp_array(const vector<T>& s,
                           const vector<int>& sa) {
    int n = int(s.size());
    assert(n >= 1);
    vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

vector<int> lcp_array(const string& s, const vector<int>& sa) {
    int n = int(s.size());
    vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}
} // namespace atcoder

const int maxn = 100010;
int n, m, q, pos[maxn], up[maxn], down[maxn], ans[maxn];
int fa[maxn], ew[maxn], dep[maxn], son[maxn], sz[maxn], top[maxn];
vector<int> str;
vector<array<int, 4>> Q[maxn * 4];
vector<array<int, 2>> G[maxn];

namespace BIT {
int c[maxn * 2];

void add(int p) {
    for (p++; p < maxn * 2; p += p & -p) c[p]++;
}

int query(int p) {
    int s = 0;
    for (p++; p; p -= p & -p) s += c[p];
    return s;
}
} // namespace BIT

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1, u, v; i < n; i++) {
        char ch;
        cin >> u >> v >> ch;
        G[u].push_back({v, ch - 'a'}), G[v].push_back({u, ch - 'a'});
    }
    for (int i = 1; i <= m; i++) {
        string t;
        cin >> t;
        for (char ch : t) str.push_back(ch - 'a');
        str.push_back(26), pos[i] = str.size();
    }
    function<void(int)> dfs1 = [&](int u) {
        sz[u] = 1, dep[u] = dep[fa[u]] + 1;
        for (auto &e : G[u]) if (e[0] ^ fa[u]) {
            fa[e[0]] = u, ew[e[0]] = e[1];
            dfs1(e[0]), sz[u] += sz[e[0]];
            if (sz[e[0]] > sz[son[u]]) son[u] = e[0];
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int anc) {
        top[u] = anc;
        if (son[u]) dfs2(son[u], anc);
        for (auto &e : G[u]) {
            if (e[0] ^ fa[u] && e[0] ^ son[u]) dfs2(e[0], e[0]);
        }
        if (!son[u]) {
            for (int i = u; ; i = fa[i]) {
                up[i] = str.size(), str.push_back(ew[i]);
                if (i == anc) break;
            }
            for (int i = anc; ; i = son[i]) {
                down[i] = str.size(), str.push_back(ew[i]);
                if (i == u) break;
            }
        }
    };
    dfs1(1), dfs2(1, 1), str.push_back(26);
    auto sa = atcoder::suffix_array(str);
    auto ht = atcoder::lcp_array(str, sa);
    vector<int> rk(str.size());
    vector<vector<int>> st(20, vector<int>(str.size()));
    for (int i = 0; i < str.size(); i++) {
        rk[sa[i]] = i;
        if (i + 1 < str.size()) st[0][i] = ht[i];
    }
    for (int k = 1; 1 << k < str.size(); k++) {
        for (int i = 0; i + (1 << k) < str.size(); i++) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
    auto lcp = [&](int i, int j) -> int {
        if (i == j) return str.size() - i;
        i = rk[i], j = rk[j];
        if (i > j) swap(i, j);
        int k = __lg(j - i);
        return min(st[k][i], st[k][j - (1 << k)]);
    };
    vector<array<int, 2>> V, _V;
    for (int i = 1, u, v, ql, qr; i <= q; i++) {
        cin >> u >> v >> ql >> qr;
        V.clear(), _V.clear();
        while (top[u] ^ top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                V.push_back({up[u], up[top[u]]}), u = fa[top[u]];
            } else {
                _V.push_back({down[top[v]], down[v]}), v = fa[top[v]];
            }
        }
        if (dep[u] > dep[v]) V.push_back({up[u], up[v] - 1});
        if (dep[u] < dep[v]) V.push_back({down[u] + 1, down[v]});
        reverse(_V.begin(), _V.end());
        copy(_V.begin(), _V.end(), back_inserter(V));
        int len = 0;
        for (auto &p : V) len += p[1] - p[0] + 1;
        auto comp = [&](int i) -> int {
            for (auto &p : V) {
                int k = min(p[1] - p[0] + 1, lcp(i, p[0]));
                if (k <= p[1] - p[0]) return str[i + k] < str[p[0] + k] ? -1 : 1;
                i += k;
            }
            return 0;
        };
        int l = 0, r = str.size() - 1, lb, rb;
        while (l <= r) {
            int mid = (l + r) / 2;
            comp(sa[mid]) >= 0 ? r = (lb = mid) - 1 : l = mid + 1;
        }
        if (comp(sa[lb])) continue;
        l = lb, r = str.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            !comp(sa[mid]) ? l = (rb = mid) + 1 : r = mid - 1;
        }
        l = pos[ql - 1], r = pos[qr] - len;
        if (l > r) continue;
        if (lb) Q[lb - 1].push_back({l, r, -1, i});
        Q[rb].push_back({l, r, 1, i});
    }
    for (int i = 0; i < str.size(); i++) {
        BIT::add(sa[i]);
        for (auto &p : Q[i]) {
            ans[p[3]] += p[2] * (BIT::query(p[1]) - BIT::query(p[0] - 1));
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
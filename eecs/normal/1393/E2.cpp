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

typedef array<int, 5> state;
const int maxn = 100010, P = 1000000007;
int n, ans, pos[maxn], len[maxn], st[20][maxn * 10];
string s, str;
vector<state> f[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        pos[i] = str.size(), len[i] = s.size();
        str.append(s);
    }
    auto sa = atcoder::suffix_array(str);
    auto ht = atcoder::lcp_array(str, sa);
    vector<int> rk(str.size());
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
        if (max(i, j) == str.size() || i == j) return str.size() - max(i, j);
        i = rk[i], j = rk[j];
        if (i > j) swap(i, j);
        int k = __lg(j - i);
        return min(st[k][i], st[k][j - (1 << k)]);
    };
    auto sign = [&](int a, int b) {
        return a < b ? 1 : a == b ? 2 : 0;
    };
    auto chk = [&](int a, int b, int c, int d) {
        int k = lcp(a, c);
        return k < min(b, d) ? str[a + k] < str[c + k] : sign(b, d);
    };
    auto comp = [&](state p, state q) -> int {
        int k = lcp(p[0], q[0]);
        if (k < min(p[1], q[1])) return str[p[0] + k] < str[q[0] + k];
        if (p[1] >= q[1]) {
            k = lcp(p[0] + q[1], q[2]);
            if (k < min(p[1] - q[1], q[3])) return str[p[0] + q[1] + k] < str[q[2] + k];
            if (p[1] - q[1] >= q[3]) return sign(p[1] + p[3], q[1] + q[3]);
            return chk(p[2], p[3], q[2] + p[1] - q[1], q[3] - p[1] + q[1]);
        }
        k = lcp(p[2], q[0] + p[1]);
        if (k < min(p[3], q[1] - p[1])) return str[p[2] + k] < str[q[0] + p[1] + k];
        if (q[1] - p[1] >= p[3]) return sign(p[1] + p[3], q[1] + q[3]);
        return chk(p[2] + q[1] - p[1], p[3] - q[1] + p[1], q[2], q[3]);
    };
    for (int i = 0; i < n; i++) {
        f[i].push_back({0, 0, pos[i], len[i], i == 0});
        for (int j = 0; j < len[i]; j++) {
            f[i].push_back({pos[i], j, pos[i] + j + 1, len[i] - j - 1, i == 0});
        }
        sort(f[i].begin(), f[i].end(), [&](state p, state q) { return comp(p, q) == 1; });
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0, k = 0, s = 0; j < f[i].size(); j++) {
            for (; k < f[i - 1].size() && comp(f[i - 1][k], f[i][j]); k++) {
                red(s += f[i - 1][k][4] - P);
            }
            f[i][j][4] = s;
        }
    }
    for (auto &p : f[n - 1]) {
        red(ans += p[4] - P);
    }
    cout << ans << '\n';
    return 0;
}
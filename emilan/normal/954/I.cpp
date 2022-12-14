#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

template <typename T>
T mod_pow(T b, long long e, T mod) {
    T r = 1;
    for (b %= mod; e > 0; e /= 2, b = b * b % mod) {
        if (e & 1) r = r * b % mod;
    }
    return r;
}

template <bool inv = false, typename T>
vector<T> ntt998244353(vector<T> a) {
    using ll = long long;
    const int kMod = 998244353;
    const int kRoot = 62;
    int n = int(size(a));

    for (int i = 1, j = 0; i < n; i++) {
        int msk = n >> 1;
        for (; j & msk; msk >>= 1) j ^= msk;
        j ^= msk;
        if (i < j) swap(a[i], a[j]);
    }

    for (int h = 1; h < n; h *= 2) {
        ll e = (inv ? kMod - 2LL : 1LL) * (kMod - 1) / (2 * h) % (kMod - 1);
        int w = int(mod_pow<ll>(kRoot, e, kMod));
        for (int i = 0; i < n; i += 2 * h) {
            int wj = 1;
            for (int j = 0; j < h; j++, wj = int(ll(w) * wj % kMod)) {
                int x = int(a[i + j]);
                int y = int(ll(wj) * a[i + j + h] % kMod);
                a[i + j] = (x + y) % kMod;
                a[i + j + h] = (x - y + kMod) % kMod;
            }
        }
    }

    if (inv) {
        int n_inv = int(mod_pow<ll>(n, kMod - 2, kMod));
        for (auto &x : a) x = int(ll(x) * n_inv % kMod);
    }
    return a;
}

template <typename T>
vector<T> convolution998244353(const vector<T> &a, const vector<T> &b) {
    const int kMod = 998244353;
    int n = int(size(a) + size(b) - 1);
    int ceil_n = 1 << __lg(2 * n - 1);

    vector<T> ca(ceil_n), cb(ceil_n);
    copy(begin(a), end(a), begin(ca));
    copy(begin(b), end(b), begin(cb));

    vector<T> fa = ntt998244353(ca);
    vector<T> fb = ntt998244353(cb);

    for (int i = 0; i < ceil_n; i++) {
        fa[i] = int((long long)(fa[i]) * fb[i] % kMod);
    }

    vector<T> cc = ntt998244353<true>(fa);
    return vector<T>(begin(cc), begin(cc) + n);
}

class Dsu {
  public:
    Dsu(int n) : n_(n), p_(n, -1), comp_cnt_(n) {}

    int comp_cnt() const { return comp_cnt_; }

    int comp_size(int u) { return -p_[root(u)]; }

    int root(int u) { return p_[u] < 0 ? u : p_[u] = root(p_[u]); }

    bool connected(int u, int v) { return root(u) == root(v); }

    bool combine(int u, int v) {
        int x = root(u), y = root(v);
        if (x == y) return false;
        if (p_[x] > p_[y]) swap(x, y);

        p_[x] += p_[y];
        p_[y] = x;
        comp_cnt_--;
        return true;
    }

    vector<vector<int>> get_comps() {
        vector<vector<int>> ans(n_);
        for (int u = 0; u < n_; u++) {
            int r = root(u);
            if (empty(ans[r])) ans[r].reserve(-p_[r]);
            ans[r].push_back(u);
        }
        ans.erase(remove(begin(ans), end(ans), vector<int>{}), end(ans));
        return ans;
    }

  private:
    int n_;
    vector<int> p_;
    int comp_cnt_;
};

void solve() {
    string s, t;
    cin >> s >> t;
    int n = SZ(s);
    int m = SZ(t);

    reverse(ALL(t));

    vector<array<array<int, 6>, 6>> pairs(n - m + 1);
    for (char s_c = 'a'; s_c <= 'f'; s_c++) {
        for (char t_c = 'a'; t_c <= 'f'; t_c++) {
            vector<int> a(n), b(m);
            for (int i = 0; i < n; i++) a[i] = s[i] == s_c;
            for (int i = 0; i < m; i++) b[i] = t[i] == t_c;

            auto conv = convolution998244353(a, b);
            for (int i = 0; i <= n - m; i++) {
                pairs[i][s_c - 'a'][t_c - 'a'] = conv[i + m - 1];
            }
        }
    }

    vector<int> ans(n - m + 1);
    for (int i = 0; i <= n - m; i++) {
        Dsu dsu(6);
        for (int u = 0; u < 6; u++) {
            for (int v = 0; v < 6; v++) {
                if (pairs[i][u][v] != 0) {
                    dsu.combine(u, v);
                }
            }
        }
        ans[i] = 6 - dsu.comp_cnt();
    }

    for (int i = 0; i <= n - m; i++) {
        cout << ans[i] << " \n"[i == n - m];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
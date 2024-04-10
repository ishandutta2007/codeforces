#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int mod = 1e9 + 7;
const int base = 5e4 + 228;

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return 1ll * a * powm(a, b - 1) % mod;
    int z = powm(a, b / 2);
    return 1ll * z * z % mod;
}

struct SegTree {
    vector<pair<int, int>> t;
    int n;

    void update(int v, int l, int r, int pos, int val) {
        if (r - l == 1) {
            t[v].first += val;
            return;
        }
        int m = (l + r) / 2;
        if (pos < m)
            update(v * 2 + 1, l, m, pos, val);
        else
            update(v * 2, m, r, pos, val);
        t[v] = max(t[v * 2 + 1], t[v * 2]);
    }

    void update(int pos, int val) {
        if (pos != -1)
            update(1, 0, n, pos, val);
    }

    pair<int, int> get(int v, int l, int r, int L, int R) {
        if (R <= l || r <= L)
            return {-228, -228};
        if (L <= l && r <= R)
            return t[v];
        int m = (l + r) / 2;
        return max(get(v * 2 + 1, l, m, L, R), get(v * 2, m, r, L, R));
    }

    pair<int, int> get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    void build(int v, int l, int r) {
        t[v] = {0, -l};
        if (r - l == 1) {
            return;
        }

        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2, m, r); 
    }
    
    void build() {
        build(1, 0, n);
    }

    SegTree(int _n) {
        n = _n;
        // int sz = 1;
        // while (sz < 2 * n)
        //     sz *= 2;
        t.resize(4 * n);
        build();
    }
};

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    vector<int> bad_word;
    string string_bad_word;
    cin >> string_bad_word;
    int m;
    cin >> m;
    vector<int> merge_string;
    vector<int> who_start;
    for (int i = 0; i < m; ++i) {
        string tmp;
        cin >> tmp;
        for (auto c : tmp) {
            who_start.emplace_back(i);
            merge_string.emplace_back(c - 'a' + m);
        }
        who_start.emplace_back(-1);
        merge_string.emplace_back(i);
    }
    for (auto c : string_bad_word) {
        bad_word.emplace_back(c - 'a' + m);
    }

    auto build_suf_array = [] (vector<int> merge_string) {
        int n = merge_string.size();
        vector<int> now_pos(n);
        {
            vector<int> cnt(*max_element(all(merge_string)) + 1);
            for (int i : merge_string)
                ++cnt[i];
            for (int i = 1; i < (int) cnt.size(); ++i)
                cnt[i] += cnt[i - 1];
            for (int i = 0; i < n; ++i)
                now_pos[i] = cnt[merge_string[i]];
        }
        for (int k = 0; (1 << k) < n; ++k) {
            vector<pair<pair<int, int>, int>> tmp(n);
            for (int i = 0; i < n; ++i) {
                tmp[i] = {{now_pos[i], now_pos[(i + (1 << k)) % n]}, i};
            }
            sort(all(tmp));
            int cnt_less = 0;
            for (int i = 0; i < n; ++i) {
                if (i != 0 && tmp[i].first != tmp[i - 1].first)
                    ++cnt_less;
                now_pos[tmp[i].second] = cnt_less;
            }
        }
        vector<int> suf_arr(n, -1);
        for (int i = 0; i < n; ++i) {
            assert(suf_arr[now_pos[i]] == -1);
            suf_arr[now_pos[i]] = i;
        }
        return suf_arr;
    };
    vector<int> suf_array = build_suf_array(merge_string);
    vector<int> who_arr;
    for (int i : suf_array) {
        who_arr.emplace_back(who_start[i]);
    }
    // Calculate sufix array

    auto calculate_hash = [&] (vector<int> s) {
        vector<int> h(s.size() + 1);
        int p = 1;
        for (int i = 0; i < (int) s.size(); ++i) {
            h[i + 1] = h[i] + 1ll * p * s[i] % mod;
            if (h[i + 1] >= mod)
                h[i + 1] -= mod;
            p = 1ll * p * base % mod;
        }
        return h;
    };
    vector<int> hash_start = calculate_hash(bad_word), hash_suf = calculate_hash(merge_string);
    vector<int> pw(max(merge_string.size(), bad_word.size()));
    {
        int now_pow = 1;
        for (int &i : pw) {
            i = powm(now_pow, mod - 2);
            now_pow = 1ll * now_pow * base % mod;
        }
    }
    // calculate hash

    auto get_hash = [&] (int l, int r, vector<int> &h) { // [l, r)
        int ans = h[r] - h[l];
        if (ans < 0)
            ans += mod;
        return 1ll * ans * pw[l] % mod;
    };

    int count_q;
    cin >> count_q;
    vector<array<int, 5>> q(count_q);
    for (int t = 0; t < count_q; ++t) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        q[t][0] = -1, q[t][1] = -1;
        {
            auto comp = [&] (int pos, int L, int R) {
                int left = 0, right = min((int) suf_array.size() - pos, R - L + 1);
                while (right - left > 1) {
                    int mid = (left + right) / 2;
                    if (get_hash(L, L + mid, hash_start) == get_hash(pos, pos + mid, hash_suf))
                        left = mid;
                    else
                        right = mid;
                }
                return bad_word[L + left] <= merge_string[pos + left];
            };
            int left = -1, right = suf_array.size() - 1;
            while (right - left > 1) {
                int mid = (left + right) / 2;
                if (comp(suf_array[mid], L - 1, R - 1))
                    right = mid;
                else
                    left = mid;
            }
            q[t][0] = right;
        }
        {
            auto comp = [&] (int pos, int L, int R) {
                if ((int) suf_array.size() - pos < R - L + 1)
                    return true;
                if (get_hash(pos, pos + R - L + 1, hash_suf) != get_hash(L, R + 1, hash_start))
                    return true;
                return false;
            };
            int left = q[t][0] - 1, right = suf_array.size();
            while (right - left > 1) {
                int mid = (left + right) / 2;
                if (comp(suf_array[mid], L - 1, R - 1))
                    right = mid;
                else
                    left = mid;
            }
            q[t][1] = right;
        }
        q[t][2] = l - 1, q[t][3] = r, q[t][4] = t;
    }
    const int K = 707;
    sort(all(q), [] (const array<int, 5> &a, const array<int, 5> &b) {
        return make_pair(a[0] / K, a[1]) < make_pair(b[0] / K, b[1]);
    });
    vector<pair<int, int>> ans(count_q);
    SegTree t(m);
    int l = 0, r = 0;
    for (auto i : q) {
        while (r < i[1])
            t.update(who_arr[r++], 1);
        while (l > i[0])
            t.update(who_arr[--l], 1);
        while (r > i[1])
            t.update(who_arr[--r], -1);
        while (l < i[0])
            t.update(who_arr[l++], -1);
        auto z = t.get(i[2], i[3]);
        ans[i[4]] = t.get(i[2], i[3]);
    }
    for (auto i : ans)
        cout << -i.second + 1 << ' ' << i.first << '\n';
}
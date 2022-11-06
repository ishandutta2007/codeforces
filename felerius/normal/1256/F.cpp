#include <bits/stdc++.h>

// Contest: Codeforces Round #598 (Div. 3) (https://codeforces.com/contest/1256)
// Problem: F: Equalizing Two Strings (https://codeforces.com/contest/1256/problem/F)

using namespace std;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        arr<int, 26> co{};
        for (auto c : s)
            co[c - 'a']++;
        auto easy = false, bad = false;
        for (int i = 0; i < 26; ++i)
            easy |= co[i] > 1;
        for (auto c : t)
            co[c - 'a']--;
        for (int i = 0; i < 26; ++i)
            bad |= co[i] != 0;

        if (bad) { cout << "NO\n"; continue; }
        if (easy) { cout << "YES\n"; continue; }

        int inv = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                inv += (t[i] < t[j]) != (s[i] < s[j]);

        cout << (inv % 2 ? "NO\n" : "YES\n");
    }

    return 0;
}
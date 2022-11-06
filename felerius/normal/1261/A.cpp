#include <bits/stdc++.h>

// Contest: Codeforces Round #602 (Div. 1, based on Technocup 2020 Elimination Round 3) (https://codeforces.com/contest/1261)
// Problem: A: Messy (https://codeforces.com/contest/1261/problem/A)

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

    int t; cin >> t;
    while (t--) {
        int n, k; string s; cin >> n >> k >> s;
        string si;
        while (k-- > 1)
            si += "()";
        int rem = n - si.size();
        for (int i = 0; i < rem / 2; ++i) si += '(';
        for (int i = 0; i < rem / 2; ++i) si += ')';
        vpi op;
        for (int i = 0; i < n; ++i) {
            if (s[i] == si[i])
                continue;
            int j = i;
            while (s[j] != si[i])
                ++j;
            op.emplace_back(i, j);
            reverse(begin(s) + i, begin(s) + j + 1);
        }

        cout << op.size() << '\n';
        for (auto [a, b] : op)
            cout << (a + 1) << ' ' << (b + 1) << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

// Contest: Codeforces Round #598 (Div. 3) (https://codeforces.com/contest/1256)
// Problem: D: Binary String Minimizing (https://codeforces.com/contest/1256/problem/D)

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
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        int j = 0;
        while (j < n && s[j] == '0')
            ++j;
        for (int i = j + 1; i < n && k > 0; ++i) {
            if (s[i] == '1')
                continue;
            if (i - j >= k) {
                swap(s[i], s[i - k]);
                break;
            }
            swap(s[i], s[j]);
            k -= i - j;
            ++j;
        }

        cout << s << '\n';
    }

    return 0;
}
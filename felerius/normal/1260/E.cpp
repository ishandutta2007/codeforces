#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 77 (Rated for Div. 2) (https://codeforces.com/contest/1260)
// Problem: E: Tournament (https://codeforces.com/contest/1260/problem/E)

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

    int n; cin >> n;
    vi a(n);
    for (auto& ai : a) cin >> ai;

    reverse(begin(a), end(a));
    while (a.back() != -1)
        a.pop_back();
    a.pop_back();

    int i = 0;
    ll res = 0;
    multiset<int> s;
    while (i < a.size()) {
        s.emplace(a[i]);
        res += *begin(s);
        s.erase(begin(s));
        n /= 2;
        for (int j = 1; i + j < a.size() && j < n; ++j)
            s.emplace(a[i + j]);
        i += n;
    }

    cout << res << '\n';
    return 0;
}
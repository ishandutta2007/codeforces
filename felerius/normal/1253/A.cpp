#include <bits/stdc++.h>

// Contest: Codeforces Round #600 (Div. 2) (https://codeforces.com/contest/1253)
// Problem: A: Single Push (https://codeforces.com/contest/1253/problem/A)

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
        int n; cin >> n;
        vi a(n);
        for (auto& ai : a) cin >> ai;
        int bi;
        for (auto& ai : a) cin >> bi, ai -= bi;
        auto it = begin(a);
        while (it != end(a) && *it == 0) ++it;
        if (it == end(a)) { cout << "YES\n"; continue; }
        auto d = *it;
        if (d > 0) { cout << "NO\n"; continue; }
        while (it != end(a) && *it == d) ++it;
        while (it != end(a) && *it == 0) ++it;
        cout << (it == end(a) ? "YES\n" : "NO\n");
    }

    return 0;
}
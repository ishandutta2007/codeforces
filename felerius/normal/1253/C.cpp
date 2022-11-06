#include <bits/stdc++.h>

// Contest: Codeforces Round #600 (Div. 2) (https://codeforces.com/contest/1253)
// Problem: C: Sweets Eating (https://codeforces.com/contest/1253/problem/C)

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

    int n, m; cin >> n >> m;
    vi a(n);
    for (auto& ai : a) cin >> ai;
    sort(begin(a), end(a));
    vector<ll> msum(n);
    for (int i = 0; i < n; ++i)
        msum[i] = a[i] + (i >= m ? msum[i - m] : 0);

    ll s = 0;
    for (int i = 0; i < n; ++i)
        s += msum[i], cout << s << ' ';
    cout << '\n';

    return 0;
}
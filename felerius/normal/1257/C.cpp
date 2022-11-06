#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 76 (Rated for Div. 2) (https://codeforces.com/contest/1257)
// Problem: C: Dominated Subarray (https://codeforces.com/contest/1257/problem/C)

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

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        for (auto& ai : a) cin >> ai;
        map<int, int> prev;
        int mx2prev = -1;
        int mn = INF;
        for (int i = 0; i < n; ++i) {
            auto it = prev.find(a[i]);
            if (it == end(prev)) {
                prev[a[i]] = i;
            } else {
                if (it->second > mx2prev)
                    mn = min(mn, i - it->second + 1);
                mx2prev = max(mx2prev, it->second);
                it->second = i;
            }
        }

        cout << (mn == INF ? -1 : mn) << '\n';
    }

    return 0;
}
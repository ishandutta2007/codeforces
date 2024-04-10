#include <bits/stdc++.h>

// Contest: Codeforces Global Round 5 (https://codeforces.com/contest/1237)
// Problem: C2: Balanced Removals (Harder) (https://codeforces.com/contest/1237/problem/C2)

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

vpi snap_y_z, snap_z, snap;

template <class It>
int y_z_group(It it, It it_end) {
    while (it + 1 < it_end)
        snap_y_z.emplace_back((*it)[3], (*(it + 1))[3]), it += 2;
    return it == it_end ? -1 : (*it)[3];
}

template <class It>
int z_group(It it, It it_end) {
    int prev = -1;
    while (it != it_end) {
        auto it2 = it;
        while (it2 != it_end && (*it2)[1] == (*it)[1])
            ++it2;
        int i = y_z_group(it, it2);
        if (i != -1) {
            if (prev != -1)
                snap_z.emplace_back(prev, i), prev = -1;
            else
                prev = i;
        }
        it = it2;
    }
    return prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<arr<int, 4>> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i][0] >> p[i][1] >> p[i][2], p[i][3] = i;
    sort(begin(p), end(p));

    auto it = begin(p);
    int prev = -1;
    while (it != end(p)) {
        auto it2 = it;
        while (it2 != end(p) && (*it2)[0] == (*it)[0])
            ++it2;
        int i = z_group(it, it2);
        if (i != -1) {
            if (prev != -1)
                snap.emplace_back(prev, i), prev = -1;
            else
                prev = i;
        }
        it = it2;
    }

    for (auto& v : {snap_y_z, snap_z, snap})
        for (auto [i, j] : v)
            cout << (i + 1) << ' ' << (j + 1) << '\n';

    return 0;
}
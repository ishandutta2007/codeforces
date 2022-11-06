#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 76 (Rated for Div. 2) (https://codeforces.com/contest/1257)
// Problem: F: Make Them Similar (https://codeforces.com/contest/1257/problem/F)

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

const ll M1 = 1e9 + 7, M2 = 1e9 + 9;
const ll P = 17;

pair<ll, ll> calchash(const vi& nums) {
    ll h1 = 0, h2 = 0;
    for (auto i : nums)
        h1 = (h1 * P + i) % M1, h2 = (h2 * P + i) % M2;
    return {h1, h2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<u32> a(n);
    for (auto& ai : a) cin >> ai;

    map<pair<ll, ll>, u32> hashes;
    vi nums(n);
    for (u32 x = 0; x < (1u << 15); ++x) {
        for (int i = 0; i < n; ++i)
            nums[i] = __builtin_popcountl((a[i] & 0x7FFF) ^ x);
        auto h = calchash(nums);
        hashes[h] = x;
    }

    vi diffs(n);
    for (u32 x = 0; x < (1u << 15); ++x) {
        for (int i = 0; i < n; ++i)
            nums[i] = __builtin_popcountl((a[i] >> 15) ^ x);
        int mx = *max_element(begin(nums), end(nums));
        for (int i = 0; i < n; ++i)
            diffs[i] = mx - nums[i];
        for (int i = 0; i <= 15 - mx; ++i) {
            auto h = calchash(diffs);
            auto it = hashes.find(h);
            if (it != end(hashes)) {
                cout << ((x << 15u) | it->second) << '\n';
                return 0;
            }
            for (auto& di : diffs)
                ++di;
        }
    }

    cout << "-1\n";
    return 0;
}
#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 79 (Rated for Div. 2) (https://codeforces.com/contest/1279)
// Problem: B: Verse For Santa (https://codeforces.com/contest/1279/problem/B)

using namespace std;

#define sz(x)       (int)size(x)
#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define reps(a,b,c) for(int a = (b); a < (c); ++a)
#define all(a)      (a).begin(),(a).end()
#define trav(a, b)  for(auto& a : b)

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = long long;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

[[maybe_unused]] const int INF = (int)1e9;
[[maybe_unused]] const ll INFL = (ll)1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        vi a(n);
        trav(ai, a) cin >> ai;

        if (a[0] > s) {
            cout << "1\n";
            continue;
        }

        ll sum = 0;
        int i = 0;
        for (; i < n && sum <= s; ++i)
            sum += a[i];
        int j = i;
        auto mxit = max_element(begin(a), begin(a) + i);
        sum -= *mxit;
        for (; j < n && sum <= s; ++j)
            sum += a[j];
        cout << (j == i ? 0 : (mxit - begin(a) + 1)) << '\n';
    }

    return 0;
}
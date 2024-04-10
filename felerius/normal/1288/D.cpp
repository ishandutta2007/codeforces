#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 80 (Rated for Div. 2) (https://codeforces.com/contest/1288)
// Problem: D: Minimax Problem (https://codeforces.com/contest/1288/problem/D)

using namespace std;

#define sz(x)       (int)size(x)
#define rep(a, b)   for(int a = 0; a < (b); ++a)
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

    int n, m; cin >> n >> m;
    vector<arr<int, 8>> a(n);
    trav(ai, a) rep(i, m) cin >> ai[i];
    int l = 0, r = INF + 1;
    pi sol = {0, 0};
    u32 full = (1u << m) - 1;
    while (r - l > 1) {
        int mi = (l + r) / 2;
        arr<int, 256> has;
        has.fill(-1);
        rep(i, n) {
            u32 ma = 0;
            rep(j, m)
                if (a[i][j] >= mi)
                    ma |= 1u << j;
            has[ma] = i;
        }
        pi s = {-1, -1};
        rep(i, full+1) rep(j, full+1) {
            if (((u32)i | (u32)j) != full)
                continue;
            if (has[i] != -1 && has[j] != -1)
                s = {has[i], has[j]};
        }
        if (s != pair(-1, -1))
            l = mi, sol = s;
        else
            r = mi;
    }

    cout << (sol.first + 1) << ' ' << (sol.second + 1) << '\n';
    return 0;
}
#include <bits/stdc++.h>

// Contest: Codeforces Round #611 (Div. 3) (https://codeforces.com/contest/1283)
// Problem: C: Friends and Gifts (https://codeforces.com/contest/1283/problem/C)

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

    int n; cin >> n;
    vi f(n);
    trav(fi, f) cin >> fi;

    vector<bool> has_in(n);
    rep(i, n)
        if (f[i] > 0)
            has_in[f[i] - 1] = true;
    vi no_in;
    rep(i, n)
        if (!has_in[i])
            no_in.push_back(i);

    int last = -1;
    rep(i, n) {
        if (f[i] != 0)
            continue;
        if (no_in.back() == i) {
            if (last != -1) {
                f[i] = f[last];
                f[last] = no_in.back() + 1;
            } else {
                assert(sz(no_in) > 1);
                f[i] = no_in[0] + 1;
                swap(no_in[0], no_in.back());
            }
        } else
            f[i] = no_in.back() + 1;
        no_in.pop_back();
        last = i;
    }

    trav(fi, f) cout << fi << ' ' ;
    cout << '\n';

    return 0;
}
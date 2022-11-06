#include <bits/stdc++.h>

// Contest: Codeforces Round #599 (Div. 1) (https://codeforces.com/contest/1242)
// Problem: A: Tile Painting (https://codeforces.com/contest/1242/problem/A)

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

    ll n; cin >> n;
    ll mn = 0;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            mn = i;
            break;
        }
    }

    if (mn == 0) {
        cout << n << '\n';
        return 0;
    }

    auto n2 = n;
    while (n2 % mn == 0)
        n2 /= mn;

    if (n2 > 1)
        cout << "1\n";
    else
        cout << mn << '\n';

    return 0;
}
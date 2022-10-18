#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

//const int A = 1e6;
//int z[A];
//
const int mod = 1000000007;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}
inline int sub(int x, int y) {
    int z = x + mod - y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}
inline int mul(int x, int y) {
    return (x * ll(y)) % mod;
}
inline int get(int x) {
    return mul(mul(x, add(x, 1)), 500000004);
}
//unordered_map<ll, int> mp;
//int solve(ll n) {
//    if (n == 0)
//        return 1;
//    if (n < A && z[n] != -1) {
//        return z[n];
//    }
//    auto it = mp.find(n);
//    if (it != mp.end()) {
//        return it->second;
//    }
//    int ans = 0;
//    ll x = 0;
//    ll q = (n >> 1LL);
//    for (int i = 0; i < 4 && q >= 0; ++i) {
//        x += solve(q);
//        --q;
//    }
//    x %= mod;
//    if (n < A) {
//        z[n] = x;
//    }
////    cerr << n << endl;
//    return mp[n] = x;
//}
//
//mt19937 mt(44115453);
//uniform_int_distribution<ll> uid(1, 1e18);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        n /= 2;
        ++n;
        ll a = n / 2;
        ll b = (n + 1) / 2;
        cout << add(get(a % mod), get(b % mod)) << "\n";
    }



}
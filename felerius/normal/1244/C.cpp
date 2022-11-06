#include <bits/stdc++.h>

// Contest: Codeforces Round #592 (Div. 2) (https://codeforces.com/contest/1244)
// Problem: C: The Football Season (https://codeforces.com/contest/1244/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, p, w, d; cin >> n >> p >> w >> d;

    auto rem = p % w;
    for (ll i = 0; i < w && d * i <= p; ++i) {
        if (d * i % w == rem) {
            auto wi = (p - d * i) / w;
            if (i + wi > n)
                cout << "-1\n";
            else
                cout << wi << ' ' << i << ' ' << (n - wi - i) << '\n';
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
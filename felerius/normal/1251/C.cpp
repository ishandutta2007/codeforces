#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 75 (Rated for Div. 2) (https://codeforces.com/contest/1251)
// Problem: C: Minimize The Integer (https://codeforces.com/contest/1251/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string a; cin >> a;
        vector<char> o, e;
        for (auto c : a) {
            if (c % 2 == 0)
                e.push_back(c);
            else
                o.push_back(c);
        }

        auto ito = begin(o), ite = begin(e);
        while (ito != end(o) && ite != end(e)) {
            if (*ito < *ite)
                cout << *ito++;
            else
                cout << *ite++;
        }
        while (ito != end(o))
            cout << *ito++;
        while (ite != end(e))
            cout << *ite++;
        cout << '\n';
    }

    return 0;
}
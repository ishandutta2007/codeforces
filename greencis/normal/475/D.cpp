#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    map<int, ll> mp;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
        mp[queries[i]] = 0;
    }

    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        v.emplace_back(a[i], 1);
        vector<pii> newv;
        for (auto [x, cnt] : v) {
            x = gcd(x, a[i]);
            if (!newv.empty() && newv.back().first == x)
                newv.back().second += cnt;
            else
                newv.emplace_back(x, cnt);
        }
        swap(v, newv);
        for (auto [x, cnt] : v) {
            auto it = mp.find(x);
            if (it != mp.end())
                it->second += cnt;
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << mp[queries[i]] << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

#define ctz __builtin_ctzll

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<array<int, 2>> ans;

    ll ops = 0;

    auto op = [&](int i, int j) {
        if (a[i] > a[j]) swap(i, j);
        a[j] -= a[i], a[i] *= 2;
        ans.pb({i, j});
        ops++;
    };

    multiset<array<ll, 2>> s;
    for (int i = 0; i < n; i++)
        if (a[i] != 0) s.insert({ctz(a[i]), i});

    if (s.size() < 2) {
        cout << "-1\n"; return 0;
    }

    while (s.size() > 2) {
        int x = (*s.begin())[1]; s.erase(s.begin());
        int y = (*s.begin())[1]; s.erase(s.begin());
        int z = (*s.begin())[1]; s.erase(s.begin());
        if (ctz(a[x]) == ctz(a[y]))
            op(x, y);
        else if (ctz(a[z]) == ctz(a[y]))
            op(z, y);
        else {
            while (ctz(a[x]) != ctz(a[y]) && ctz(a[y]) != ctz(a[z]))
                op(x, z);
            if (ctz(a[x]) == ctz(a[y]))
                op(x, y);
            else if (ctz(a[z]) == ctz(a[y]))
                op(z, y);
        }
        if (a[x] != 0) s.insert({ctz(a[x]), x});
        if (a[y] != 0) s.insert({ctz(a[y]), y});
        if (a[z] != 0) s.insert({ctz(a[z]), z});
    }

    cout << ans.size() << "\n";
    for (auto& [i, j] : ans)
        cout << i+1 << " " << j+1 << "\n";
}
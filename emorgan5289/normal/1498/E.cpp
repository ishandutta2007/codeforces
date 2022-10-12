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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    vector<array<int, 2>> v;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            v.pb({i, j});
    sort(all(v), [&](auto i, auto j){ return abs(d[i[0]]-d[i[1]]) > abs(d[j[0]]-d[j[1]]); });
    for (auto [i, j] : v) {
        if (d[i] < d[j]) swap(i, j);
        cout << "? " << i+1 << " " << j+1 << endl;
        string r; cin >> r;
        if (r == "Yes") {
            cout << "! " << i+1 << " " << j+1 << endl;
            exit(0);
        }
    }
    cout << "! 0 0" << endl;
}
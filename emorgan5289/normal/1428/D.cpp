#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<array<int, 2>> ones;
    vector<int> twos;
    int r = 0;
    vector<array<int, 2>> out;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == 1) {
            ones.pb({i+1, r}), out.pb({i+1, r++});
        } else if (a[i] == 2) {
            if (ones.empty()) {
                cout << "-1\n", exit(0);
            }
            out.pb({i+1, ones.back()[1]});
            twos.pb(i+1);
            ones.pop_back();
        } else if (a[i] == 3) {
            int x = -1;
            if (!twos.empty()) {
                x = twos.back(); twos.pop_back();
            } else if (!ones.empty()) {
                x = ones.back()[0]; ones.pop_back();
            } else {
                cout << "-1\n", exit(0);
            }
            out.pb({x, r});
            out.pb({i+1, r++});
            twos.pb(i+1);
        }
    }
    cout << out.size() << "\n";
    for (auto& [x, y] : out) {
        cout << n-y << " " << x << "\n";
    }
}
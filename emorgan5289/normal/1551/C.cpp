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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        auto val = [&](string a, char c) {
            int x = 0;
            for (char y : a)
                x += y == c ? 1 : -1;
            return x;
        };
        ll ans = 0;
        for (char c = 'a'; c <= 'e'; c++) {
            sort(all(s), [&](string a, string b){
                return val(a, c) > val(b, c);
            });
            ll x = 0, y = 0;
            for (auto& a : s)
                if (x+val(a, c) > 0)
                    x += val(a, c), y++;
            cmax(ans, y);
        }
        cout << ans << "\n";
    }
}
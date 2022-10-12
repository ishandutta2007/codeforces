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

priority_queue<pair<ll, int>> p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    ll d = 0, r = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') d--;
        if (s[i] == '(') d++;
        if (s[i] == '?') {
            ll x, y; cin >> x >> y;
            d--, s[i] = ')';
            r += y;
            p.push({y-x, i});
        }
        if (d < 0) {
            if (p.empty())
                return cout << "-1\n", 0;
            auto [x, j] = p.top(); p.pop();
            r -= x, d += 2, s[j] = '(';
        }
    }
    if (d != 0)
        return cout << "-1\n", 0;
    cout << r << "\n" << s << "\n";
}
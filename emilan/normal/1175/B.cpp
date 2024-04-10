#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x = 0;
    stack<ll> s;
    s.emplace(1);

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;

        if (t == "for") {
            int i;
            cin >> i;
            
            ll m = s.top() * ll(i);
            if (s.top() == -1 || m >= 1ll << 32) {
                s.push(-1);
            } else {
                s.push(m);
            }
        } else if (t == "end") {
            s.pop();
        } else {
            if (s.top() == -1) {
                cout << "OVERFLOW!!!";
                return 0;
            } else {
                x += s.top();
            }
        }
    }

    if (x >= 1ll << 32) cout << "OVERFLOW!!!";
    else cout << x;
}
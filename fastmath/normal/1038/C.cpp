#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    multiset <int> a, b;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.insert(x);
    }

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.insert(x);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a.size() && (b.empty() || *a.rbegin() > *b.rbegin())) {
            ans += *a.rbegin();
            a.erase(a.find(*a.rbegin()));                     
        }
        else {
            b.erase(b.find(*b.rbegin()));
        }

        if (a.size() && (b.empty() || *a.rbegin() > *b.rbegin())) {
            a.erase(a.find(*a.rbegin()));
        }
        else {
            ans -= *b.rbegin();
            b.erase(b.find(*b.rbegin()));
        }
    }

    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

#define nope return void(cout << "no\n")

void solve() {
    int u, v;
    cin >> u >> v;

    int cu = __builtin_popcount(u);
    int cv = __builtin_popcount(v);
    if (cu < cv) nope;

    int safe = -1;
    for (int i = 29; ~i; i--) {
        if (v >> i & 1 && ~u >> i & 1) {
            safe = i;
            break;
        }
    }
    
    for (int i = safe - 1; i >= 0 && cu > cv; i--) {
        if (u >> i & 1) {
            u &= ~(1 << i);

            if (u >> safe & 1) cu--;

            u |= 1 << safe;
        }
    }

    if (cu > cv) nope;

    for (int i = 29; ~i; i--) {
        if (v >> i & 1) {
            int p = __lg(u);
            if (p > i) nope;

            u &= ~(1 << p);
        }
    }

    cout << "yes\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}